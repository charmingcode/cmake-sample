#include "hello.h"

Hello2::Hello2(std::string name) : name_(name) {}

void printHello() {
  std::cout << "Hello2" << std::endl;
}

void Hello2::sayHello() {
  std::cout << "Hello " << name_ << "!" << std::endl;
  printHello();
}
