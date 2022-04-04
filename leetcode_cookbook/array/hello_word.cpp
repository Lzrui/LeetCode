#include <iostream>
using namespace std;
 class A{
 private:
     int a;
     static int b;
 };
int A::b = 5;
int main() 
{
    A c;
    cout << "Hello, World!";
    return 0;
}
