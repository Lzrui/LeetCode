#include<bits/stdc++.h>

using namespace std;

class MyCircularDeque {
 private:
  int front;
  int rear;
  int capacity;
  vector<int> elements;

 public:
  MyCircularDeque(int k) : front(0), rear(0), capacity(k + 1), elements(vector<int>(capacity)) {}

  bool insertFront(int value) {
    if (isFull())
      return false;
    front = (capacity + front - 1) % capacity;
    elements[front] = value;
    return true;
  }

  bool insertLast(int value) {
    if (isFull())
      return false;
    elements[rear] = value;
    rear = (rear + 1) % capacity;
    return true;
  }

  bool deleteFront() {
    if (isEmpty())
      return false;
    front = (front + 1) % capacity;
    return true;
  }

  bool deleteLast() {
    if (isEmpty())
      return false;
    rear = (capacity + rear - 1) % capacity;
    return true;
  }

  int getFront() {
    if (isEmpty())
      return -1;
    return elements[front];
  }

  int getRear() {
    if (isEmpty())
      return -1;
    return elements[(capacity + rear - 1) % capacity];
  }

  bool isEmpty() {
    return front == rear;
  }

  bool isFull() {
    return front == (rear + 1) % capacity;
  }

};

int main() {
  return 0;
}