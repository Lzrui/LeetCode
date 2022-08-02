#include<bits/stdc++.h>

using namespace std;

class MyCircularQueue {
 private:
  int front;
  int rear;
  int capacity;
  vector<int> elements;

 public:
  explicit MyCircularQueue(int k) {
    this->capacity = k + 1;
    this->elements = vector<int>(capacity);
    rear = front = 0;
  }

  bool enQueue(int value) {
    if (isFull()) {
      return false;
    }
    elements[rear] = value;
    rear = (rear + 1) % capacity;
    return true;
  }

  bool deQueue() {
    if (isEmpty()) {
      return false;
    }
    front = (front + 1) % capacity;
    return true;
  }

  int Front() {
    if (isEmpty()) {
      return -1;
    }
    return elements[front];
  }

  int Rear() {
    if (isEmpty()) {
      return -1;
    }
    return elements[(rear - 1 + capacity) % capacity];
  }

  bool isEmpty() const {
    return rear == front;
  }

  bool isFull() const {
    return ((rear + 1) % capacity) == front;
  }
};

int main(){
  auto* obj = new MyCircularQueue(5);
  bool param_1 = obj->enQueue(1);
  bool param_2 = obj->enQueue(2);
  bool param_3 = obj->enQueue(3);
  bool param_4 = obj->enQueue(4);
  bool param_10 = obj->enQueue(5);
  bool param_5 = obj->deQueue();
  bool param_11 = obj->enQueue(6);
  int param_6 = obj->Front();
  int param_7 = obj->Rear();
  bool param_8 = obj->isEmpty();
  bool param_9 = obj->isFull();
  return 0;
}