#include <iostream>
#include <stdexcept>


class FirstClass {
  public:
    FirstClass(const std::string& param) {
      if(param.size() < 5)
        throw std::invalid_argument("String length not sufficient for FirstClass object construction");
      member = param;
    }
    ~FirstClass() { std::cout << "[~FirstClass] " << member << '\n'; }

  private:
    std::string member;
};

class SecondClass: public FirstClass {
  public:
    SecondClass(const std::string& parent_param, const std::string& child_param): FirstClass(parent_param), member(child_param) {}
    ~SecondClass() { std::cout << "[~SecondClass] " << member << '\n'; }
  
  private:
    std::string member;
};


class ThirdClass: public FirstClass {
  public:
    ThirdClass(const std::string& parent_param, const std::string& child_param): FirstClass(parent_param) {
      if(child_param.size() < 3) 
        throw std::invalid_argument("String length not sufficient for ThirdClass object construction");
      member = child_param;
    }
    ~ThirdClass() { std::cout << "[~ThirdClass] " << member << '\n'; }

  private:
    std::string member;
};


class AbstractBaseClass {
  public:
    ~AbstractBaseClass() {
      std::cout << "~AbstractBaseClass()" << '\n';
    }
    virtual void method() = 0;
};


class DerivedClass : public AbstractBaseClass {
  public:
    DerivedClass(std::string param) {
      if(param.size() < 5)
        throw std::invalid_argument("String length not sufficient for DerivedClass object construction");
      member = param;
    }

    void method() override {
      std::cout << "DerivedClass::method()" << '\n';
    }

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

  SecondClass obj_3(std::string("hello"), std::string("world"));
  try {
    // Note that the object is not yet constructed, so destructor will not be
    // called for both the parent and the child class. In this case the
    // exception is in the parent class
    SecondClass obj_4(std::string("eat"), std::string("apple"));
  }
  catch (const std::exception& e) {
    std::cout << e.what() << '\n';
  }

  ThirdClass obj_5(std::string("jibber"), std::string("jabber"));
  try {
    // Note that the ThirdClass object is not yet constructed so the destructor
    // of the ThirdClass object will not be called. But the inherited parent
    // class FirstClass was constructed succesfully, so the destructor for
    // "Nemesis" will be called while going out of scope
    ThirdClass obj_6(std::string("Nemesis"), std::string("oh"));
  }
  catch (const std::exception& e) {
    std::cout << e.what() << '\n';
  }

  DerivedClass obj_7("sample");
  try {
    DerivedClass obj_8(std::string("abc"));
  }
  catch (const std::exception& e) {
    std::cout << e.what() << '\n';
  }

  return 0;
}
