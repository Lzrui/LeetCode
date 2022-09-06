#include <bits/stdc++.h>
using namespace std;

// 实现一个简单的智能指针，利用模板实现泛型编程
template <class T>
class MySharedPtr
{
 private:
  int *count; // 引用计数
  T *ptr; // 指针对象

 public:
  MySharedPtr(T *p = nullptr); // 默认构造函数
  MySharedPtr(const MySharedPtr<T> &ohter);
  ~MySharedPtr();
  T *operator->();
  T &operator*();
  MySharedPtr<T> &operator=(MySharedPtr<T> &other);
  MySharedPtr<T> &operator=(T *ptr);
  int getRef();
};

template <class T> // 成员函数类外实现，需要template <class T>标识
MySharedPtr<T>::MySharedPtr(T *p)
{
  cout << "constructor" << endl;
  this->count = new int(1);
  this->ptr = (T *)p;
}

template <class T> // 成员函数类外实现，需要template <class T>标识
MySharedPtr<T>::MySharedPtr(const MySharedPtr<T> &ohter)
{
  cout << "copy func" << endl;
  this->count = &(++*ohter.count);
  this->ptr = ohter.ptr;
}

template <class T>
MySharedPtr<T>::~MySharedPtr()
{
  cout << "des" << endl;
  if (--*count == 0)
  {
    delete count;
    count = nullptr;
    delete ptr;
    ptr = nullptr;
  }
}

// 类成员访问运算符->重载   语句 p->m 被解释为 (p.operator->())->m
template <class T>
T *MySharedPtr<T>::operator->()
{
  cout << "operator->" << endl;
  return ptr;
}

template <class T>
T &MySharedPtr<T>::operator*()
{
  cout << "operator*" << endl;
  return *ptr;
}

template <class T>
MySharedPtr<T> &MySharedPtr<T>::operator=(MySharedPtr<T> &other)
{
  cout << "operator=1" << endl;
  if (this == &other)
  {
    return *this;
  }
  --*this->count;
  if (*this->count == 0)
  {
    delete this->count;
    delete this->ptr;
  }
  ++*other.count;
  this->ptr = other.ptr;
  this->count = other.count;
  return *this;
}

template <class T>
MySharedPtr<T> &MySharedPtr<T>::operator=(T *ptr)
{
  cout << "operator=2" << endl;
  if (this->ptr == ptr)
  {
    return *this;
  }
  --*this->count;
  if (*this->count == 0)
  {
    delete this->count;
    delete this->ptr;
  }
  this->count = new int(1);
  this->ptr = ptr;
  return *this;
}

template <class T>
int MySharedPtr<T>::getRef()
{
  return *count;
}

class Test
{
 private:
  /* data */
 public:
  Test(/* args */);
  ~Test();
  void test();
};

Test::Test(/* args */)
{
  cout << "Test construcotr" << endl;
}

Test::~Test()
{
  cout << "Test des" << endl;
}

void Test::test()
{
  cout << "it's a test" << endl;
}

int main()
{
  MySharedPtr<Test> sPtr(new Test()); // 默认构造函数
  sPtr->test();
  MySharedPtr<Test> sPtr2 = sPtr; // 拷贝构造函数
  sPtr2->test();
  MySharedPtr<Test> sPtr3(sPtr); // 拷贝构造函数
  sPtr3 = new Test();            // 赋值运算符2
  sPtr3 = sPtr2;                 // 赋值运算符1
  MySharedPtr<Test> sPtr4;       // 默认构造函数，ptr = nullptr
  sPtr4 = new Test();            // 赋值运算符2
  //  MySharedPtr<Test> sPtr4 = MySharedPtr<Test>(new Test());
  Test *p = new Test();
  MySharedPtr<Test> sPtr5(p);
  MySharedPtr<Test> sPtr6;
  sPtr6 = new Test();

  Test *p7 = new Test();
  MySharedPtr<Test> sPtr7 = p7;         //
  MySharedPtr<Test> sPtr8 = new Test(); // 看运行结果只用到了默认构造函数，但是实际上编译器进行了优化，但是按照正常流程应该需要调用拷贝构造函数，将临时对象拷贝给sPtr8
  // 但是拷贝构造函数不接收非const类型的临时变量，因此如何想以上面这两种形式初始化对象，必须将拷贝构造函数的参数设置为const类型，解释如下：
  // 当一个函数的形参为非const类型，而一个参数以非const传入，
  // 编译器一般会认为程序员会在该函数里修改该参数，而且该参数返回后还会发挥作用。
  // 此时如果你把一个临时变量当成非const引用传进来，由于临时变量的特殊性，
  // 程序员无法对改临时变量进行操作，同时临时变量可能随时会消失，
  // 修改临时变量也毫无意义，因此，临时变量不能作为非const引用。
  return 0;
}