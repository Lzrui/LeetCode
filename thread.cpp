//
// Created by l50021384 on 2022/8/4.
//
#include <iostream>
#include <thread>
void threadproc() {
  while(true) {
    std::cout << "I am New Thread!" << std::endl;
  }
}
void func() {
  std::thread t(threadproc);
  t.detach();
}
int main() {
  func();
  while(true) {} //ᦏԆᕚᑕӧᥝᭅڊ
  return 0; }
