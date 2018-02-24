#include <iostream>
#include <queue>
#include <string>

class Base
{
public:
    void g(float x){std::cout << "Base::g(float)" << x <<std::endl;}       //注意c++中将在类声明中定义了实现的函数自动默认为内联函数
    void h(float x){std::cout << "Base::h(float)" << x <<std::endl;}
};

class Derived : public Base
{
public:
    void g(int x){std::cout << "Derived::g(int)" << x <<std::endl;}
    void h(float x){std::cout << "Derived::h(float)" << x <<std::endl;}
};

void OverLoadRideTestMain(void)
{
  Derived d;
  Base* pb = &d;
  Derived* pd = &d;
  //behavior depends on type of pointer
  pb->g(3.14f);     //Base::g(float) 3.14;
  pd->g(3.14f);     //Derived::g(int) 3;

  pb->h(3.14f);     //Base::h(float) 3.14;
  pd->h(3.14f);     //Derived::h(float) 3.14;
};

void printQ(std::deque<std::string> q) {
  while(!q.empty()) {
    std::cout << q.front() << " ";
    q.pop_front();
  }
  std::cout << std::endl;
}

int main(void) {
  std::cout << "Hello World2!" << std::endl;
  std::deque<std::string> q1;
  q1.push_back("1");
  q1.push_back("2");
  q1.push_back("3");

  std::deque<std::string> q2 = q1;

  q1.pop_front();
  printQ(q1);
  printQ(q2);

  std::deque<std::string> q3 = q1;

  OverLoadRideTestMain();

}