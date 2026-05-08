#include<iostream>
using namespace std;

class Person{
  public:  
  template <class T>
  T getValue(T value);
};

template <class T>
T Person::getValue(T value){ // Here this show a function template or member function template 
  return value;
}

int main(){
  Person p;
  cout<<"Value is: "<<p.getValue(8.6)<<endl;
  return 0;
}
