#include <iostream>
#include <memory>
#include <exception>
#include <string>


struct FileDeleter {
  void operator()(FILE* file) {
    fclose(file);
    std::cout << "Closing file" << '\n';
  }
};


class FileHandler {
  public:
    FileHandler(const char* file_path, const char* mode): file_ptr(fopen(file_path, mode)) {}
  
  private:
    std::unique_ptr<FILE, FileDeleter> file_ptr;
};


int main(void) {
  FileHandler f("hello.txt", "w");
  try {
    std::string("abc").substr(10);
  }
  catch (const std::exception& e) {
    std::cout << e.what() << '\n';
    // Uncommenting this will automatically cleanup FileHandler file due to
    // stack unwinding
    throw;
  }
  return 0;
}
