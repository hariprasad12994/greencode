#include <iostream>
#include <memory>

enum CommandType{
    Read, Write, Execute
};

template <typename T>
class AbstractCommand{
    public:
        explicit AbstractCommand();
        ~AbstractCommand();
        virtual void execute() = 0;
        static bool check_type (CommandType type){
            return type_ == type;
        }
        // template function to return a new object on heap using base class
        // pointer??? Function must also forward all arguments properly
        std::unique_ptr<AbstractCommand> create_command(){
            return std::make_unique<AbstractCommand>(new T());
        }

    private:
        static const CommandType type_;
};

//std::unique_ptr<AbstractCommand> command_factory(CommandType type_){
    //// how to store all the static methods here to an std::array
    //// can they also be stored with base class pointer
    //// iterate the array if the type matches return the newly created object
    //// how about the other arguments to the constructor???
    // It is possible to store as normal points since static member functions
    // are treated as normal function and not Class::mem*
    ////
//}

class Command{
    public:
        Command(std::string arg)
            : pimpl_{std::make_unique<CommandImpl>()}, arg_(arg)
                {}

        void operator()() const { pimpl_->execute(this->arg_); }

    private:

    struct CommandBase{ // External polymorphism design pattern
        virtual ~CommandBase() = default;
        virtual void execute(std::string arg) = 0; // possibly add arguments here in future extension
    };

    struct CommandImpl : public CommandBase{
        void execute(std::string arg) final { std::cout << arg << '\n'; }
    };

    std::unique_ptr<CommandBase> pimpl_; // pimpl idiom, simple form of bridge design pattenr
    std::string arg_;
};

class DummyClass{
    public:
        DummyClass(std::string arg) : arg_(arg) {}
        ~DummyClass() = default;
        static std::unique_ptr<DummyClass> creat_dummyObj(std::string arg){
            return std::make_unique<DummyClass>(arg);
        }
        void print_arg(){ std::cout << arg_ << '\n'; }
    private:
        std::string arg_;
};

int main(void){
    Command c(std::string("hello"));
    auto d = DummyClass::creat_dummyObj(std::string("world"));
    c();
    d->print_arg();
    return 0;
}

