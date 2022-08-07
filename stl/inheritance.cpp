#include <iostream>


class FirstClass { 
  public:
    FirstClass(int mem_1, int mem_2): mem_1(mem_1), mem_2(mem_2) {}

  protected:
    int mem_1;
    int mem_2;
};


class SecondClass: public FirstClass {
  public:
    SecondClass(int mem_1, int mem_2, int mem_3): FirstClass(mem_1, mem_2), mem_1(mem_3) {}
    void first_class() { std::cout << FirstClass::mem_1 << "  " << mem_2 << '\n'; }
    void second_class() { std::cout << mem_1 << '\n'; }

  private:
    int mem_1;
};


int main(void) {
  SecondClass obj_1(1, 2, 3);
  // print all inherited members
  obj_1.first_class();
  // print current class members
  obj_1.second_class();

  return 0;
}
