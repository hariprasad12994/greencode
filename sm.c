#include <stdio.h>

typedef unsigned char state_t;
typedef unsigned char bool;

typedef struct state_machine_entry_t{
    state_t current_state;
    state_t next_state;
    void(*on_transition_action)(void);
    void(*current_action)(void);
    bool(*guard)(void);
}state_machine_entry_t;

#define OFF 0
#define ON 1

typedef struct state_machine_t{
    state_t current_state;
    const unsigned char num_of_state_machine_entries;
    state_machine_entry_t* state_machine_entries;
}state_machine_t;

unsigned char led_switch = OFF;

void on_to_off_action(void){
    printf("[Transition] LED switching off\n");
}

void off_to_on_action(void){
    printf("[Transition] LED switching on\n");
}

bool off_to_on_guard(void){
    return led_switch == ON;
}

bool on_to_off_guard(void){
    return led_switch == OFF;
}

void on_actions(void){
    printf("[Output] LED blinking\n");
}

void off_actions(void){
    printf("[Output] LED idle\n");
}

void execute_state_machine(state_machine_t* fsm){
    unsigned char iter = 0;
    for(iter = 0; iter < fsm->num_of_state_machine_entries; iter++){
        if(fsm->current_state == fsm->state_machine_entries[iter].current_state){
            fsm->state_machine_entries[iter].current_action();
            if(fsm->state_machine_entries[iter].guard()){
                fsm->current_state = fsm->state_machine_entries[iter].next_state;
                fsm->state_machine_entries[iter].on_transition_action();
                break;
            }
        }
    }
}

state_machine_entry_t led_state_machine_entries[] =
{
    {OFF, ON, &off_to_on_action, &off_actions, &off_to_on_guard},
    {ON, OFF, &on_to_off_action, &on_actions,  &on_to_off_guard}
};

state_machine_t led_state_machine = 
{
    OFF,
    2,
    &led_state_machine_entries
};

int main(void){
    bool test_inputs[] = {OFF, OFF, ON, ON, ON, OFF, OFF};
    unsigned char num_of_inputs = sizeof(test_inputs)/sizeof(test_inputs[0]);
    unsigned char iter = 0;

    for(iter = 0; iter < num_of_inputs; ++iter){
        printf("[Input] Current switch state = %d\n", test_inputs[iter]);
        led_switch = test_inputs[iter];
        execute_state_machine(&led_state_machine);
    }
    return 0;
}
