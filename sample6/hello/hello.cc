#include "hello.h"

Hello::Hello(std::string name) : name_(name) {}

void printHello() {
  std::cout << "Hello1" << std::endl;
}

void Hello::sayHello() {
  std::cout << "Hello " << name_ << "!" << std::endl;
  printHello();
}
