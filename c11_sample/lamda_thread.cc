#include <iostream>
#include <vector>
#include <string>
#include <thread>

using namespace std;
void GeneratorThread(int thread_num, int *status, int *produce) {

  std::chrono::milliseconds dura((0+thread_num)*1000);
  std::this_thread::sleep_for(dura);
  auto generator = [&]() -> int {
      return  (*produce)++;
  };
  for(int n = 0; n<thread_num*2; n++) {
    generator();
  }
  *status = 1;
  cout<<"finish thread_id = "<<__libcpp_thread_get_current_id()<<", thread_num = "<<thread_num<<endl;
}

int main(void) {
  std::cout << "Hello c11-lamda-thread!" << std::endl;
  std::vector<std::thread> threads;
  int thread_num = 12;
  std::vector<int> status(thread_num, 0);
  std::vector<int> produce(thread_num, 0);
  for(int i = 0; i < thread_num; i++) {
    threads.emplace_back(&GeneratorThread, i, &status[i], &produce[i]);
  }

  int n = 0;
  for(auto& t : threads) {
    n++;
    t.join();
    cout<<"join n = "<<n<<endl;
  }

  for(auto& s : status) {
    cout<<"status = "<<s<<endl;
  }

  for(auto& p : produce) {
    cout<<"produce = "<<p<<endl;
  }
}