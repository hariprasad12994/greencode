#include <iostream>
#include <stdexcept>


class FirstClass {
  public:
    FirstClass(const std::string& param) {
      if(param.size() < 5)
        throw std::invalid_argument("String length not sufficient");
      member = param;
    }
    ~FirstClass() { std::cout << "~FirstClass" << '\n'; }

  private:
    std::string member;
};


int main(void) {
  FirstClass obj_1(std::string("hello"));
  try {
    // Note that the object is not yet constructed, so destructor will not be
    // called
    FirstClass obj_2(std::string("eat"));
  } 
  catch (const std::exception& e) {
    std::cout << e.what() << '\n';
  }

  return 0;
}
