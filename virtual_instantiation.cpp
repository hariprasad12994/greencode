#include <iostream>


class SomeClass{
    private:
        int m_;
    public:
        explicit SomeClass(){};
        ~SomeClass();
        virtual void calc() = 0;
};

int main(void){
    SomeClass s;
    return 0;
}
