#ifndef __HELLO2_H
#define __HELLO2_H

#include <iostream>
#include <string>

class Hello2 {
  public:
    Hello2(std::string name);
    void sayHello();

  private:
    std::string name_;
};

#endif

