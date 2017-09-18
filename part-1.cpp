#include <thread>
#include <iostream>
#include <vector>

void hello () {
  std::cout << "Hello from thread " << std::this_thread::get_id() << '\n';
}

int main () {
  // start thread from function 
  std::vector<std::thread> threads;
  
  for(int i = 0; i < 5; ++i){
    threads.push_back(std::thread(hello));
  }
  
  // start thread from lambda
  std::vector<std::thread> lambda_threads;
  for(int i = 0; i < 5; i++) {
    lambda_threads.push_back(std::thread([](){
      std::cout << "Hello from a lambda threads" << std::this_thread::get_id() << '\n';
    }));
  }

  for(auto& thread : threads){
    thread.join();
  }
  
  for(auto& thread : lambda_threads){
    thread.join();
  }
  
  return 0;
}
