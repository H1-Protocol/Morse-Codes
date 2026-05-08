#include<iostream>
using namespace std;

template <class T>
class Person{
  T value;

  public:
  Person(T value){
    this->value = value;
  }

  void setValue(T value){
    this->value = value;
  }

  T getValue();  
  //T getValue(){ //getValue() method defined inside the class
  //  return value;
  //}
};

template <class T>
T Person <T>::getValue(){ //getValue() method defined outside the class// Person <T> tells that Person is a template
  return value;           // without <T> will show only function template or member function template not class template.
}

int main(){
  Person<string> p("Ali");
  cout<<p.getValue()<<endl;
  p.setValue("Ahmad");
  cout<<p.getValue()<<endl;
  return 0;
}
