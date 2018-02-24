#include "hello/hello.h"
#include "hello2/hello.h"

int main(void) {
  Hello hi("CMake");
  Hello2 hi2("CMake");

  hi.sayHello();
  hi2.sayHello();

  return 0;
}
