#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node{
    struct Node* next;
    int val;
}Node;

Node* Stack = NULL;
Node* Queue = NULL;

void enqueue(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    if(Queue == NULL){
        newNode->next = Queue;
        Queue = newNode;
        return;
    }
    Node* walker = Queue;
    while(walker->next != NULL){
        walker = walker->next;
    }
    newNode->next = walker->next;
    walker->next = newNode;
}

void dequeue(){
    if(Queue == NULL)
        return;
    Node* temp = Queue;
    Queue = temp->next;
    free(temp);
}

void push(int val){
    struct Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = Stack;
    Stack = newNode;
}

void pop(){
    if(Stack == NULL)
        return;
    Node* temp = Stack;
    Stack = Stack->next;
    free(temp);
}

void printList(Node* startNode){
    Node* walker = startNode;
    while(walker != NULL){
        printf("%d ", walker->val);
        walker = walker->next;
    }
    printf("\n");
}

int main(void){
    push(10);
    push(81);
    push(34);
    push(6);
    printList(Stack);
    pop();
    pop();
    printList(Stack);
    pop();
    pop();
    printList(Stack);

    enqueue(10);
    printList(Queue);
    enqueue(98);
    printList(Queue);
    enqueue(31);
    printList(Queue);
    enqueue(66);
    printList(Queue);
    dequeue();
    dequeue();
    printList(Queue);
    dequeue();
    dequeue();
    printList(Queue);

    return 0;
}


