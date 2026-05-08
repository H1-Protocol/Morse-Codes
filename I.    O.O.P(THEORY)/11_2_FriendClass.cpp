#include <iostream>
using namespace std;

class A{
  friend void func1(); 
  // friend void func2();
  protected:
    int x;
};

class B : public A{
  // friend void func1();
  friend void func2();
  int y;
};

void func1(){
  B obj;
  obj.x = 1;
  //obj.y = 2; // Cannot access,not a friend of B
}

void func2(){
  B obj;
  obj.x = 1; // Cannot access,not a friend of A
  obj.y = 2;
}

int main(){
  return 0;
}
