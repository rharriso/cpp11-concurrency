#include <thread>
#include <iostream>
#include <vector>

struct Counter {
  std::mutex mutex;
  int value;

  Counter() : value(0){}

  void increment(){
    // mutex.lock();
    std::lock_guard<std::mutex> guard(mutex);
    ++value;
    // mutex.unlock();
  }
};

int main () {
  Counter counter;

  auto threads = std::vector<std::thread>();

  for (int i = 0; i < 500; i++) {
    threads.push_back(std::thread([&counter](){
      for (int j = 0; j < 1000; j++) {
        counter.increment();
      }
    }));
  }

  for (auto &thread : threads) {
    thread.join();
  }

  std::cout << counter.value << '\n';
}