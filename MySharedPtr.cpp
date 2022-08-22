#include<bits/stdc++.h>

using namespace std;

template<typename T>
class MySharedPtr {
 private:
  int *count;
  T *ptr;
 public:
  explicit MySharedPtr(T *p = nullptr);
  MySharedPtr(const MySharedPtr<T> &other);
  ~MySharedPtr();
  T *operator->() const;
  T &operator*() const;
  MySharedPtr<T> &operator= (MySharedPtr<T> &other);
  MySharedPtr<T> &operator= (T *other);
  int GetRef();
};

template <typename T>
MySharedPtr<T>::MySharedPtr(T *p): count(new int(1)), ptr(p) {}

template <typename T>
MySharedPtr<T>::MySharedPtr(const MySharedPtr<T> &other): count(&(++*other.count)), ptr(other.ptr) {}

template <typename T>
MySharedPtr<T>::~MySharedPtr() {
  if (--*count == 0) {
    delete count;
    count = nullptr;
    delete ptr;
    ptr = nullptr;
  }
}

template <typename T>
T *MySharedPtr<T>::operator->() const {
  return ptr;
}

template <typename T>
T &MySharedPtr<T>::operator*() const {
  return *ptr;
}
template <typename T>
MySharedPtr<T> &MySharedPtr<T>::operator= (MySharedPtr<T> &other) {
  if (&other == this)
    return *this;
  if (--*count == 0) {
    delete count;
    delete ptr;
  }
  count = &(++*other.count);
  ptr = other.ptr;
  return *this;
}

template <typename T>
MySharedPtr<T> &MySharedPtr<T>::operator= (T *other) {
  if (other == ptr)
    return *this;
  if (--*count == 0) {
    delete count;
    delete ptr;
  }
  count = new int(1);
  ptr = other;
  return *this;
}

template <typename T>
int MySharedPtr<T>::GetRef() {
  return *count;
}

int main() {
  MySharedPtr<int> a(new int(5));
  MySharedPtr<int> b(a);
  int c = *a;
  int cnt = a.GetRef();
  return 0;
}