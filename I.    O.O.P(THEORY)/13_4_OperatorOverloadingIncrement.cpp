#include <iostream>
using namespace std;

class MyClass
{
public:
  MyClass()
  {
    value = 0;
  }

  // Pre increment the value of the object, Faster (no copy), returns updated value
  MyClass& operator++()
  {
    value++;
    return *this;
  }

  // Post increment the value of the object, Slower (copy of the object is created), returns old value
  MyClass operator++(int)
  {
      MyClass temp = *this;  // copy old value
      value++;               // increment current object
      return temp;           // return old value
  }
  int value;
};

int main()
{
  MyClass a;
  cout << a.value << endl;
  ++a;
  cout << a.value << endl;
  a++;
  cout << a.value << endl;
  return 0;
}
