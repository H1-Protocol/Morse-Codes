#include<iostream>
using namespace std;

class ArrayValue{
public:
  int* values;
  int size;

  ArrayValue(){
    this->size = 0;
    values = new int[size];
  }

  ArrayValue(int size){
    this->size = size;
    values = new int[size];
    for(int i=0; i<size; i++){
      values[i] = i + 1;      
    }
  }
  
  void print(){
    cout<<"Valuse are: "<<endl;
    for(int i=0; i<size; i++){
      cout<<this->values[i]<<" ";      
    }
  }

  ArrayValue& operator=(ArrayValue& obj){
  //void operator=(ArrayValue& obj){
    size = obj.size;
    values = new int[obj.size];
    for(int i=0; i<size; i++){
      values[i] =  obj.values[i];      
    }
    return *this;
  }
};

int main(){
  ArrayValue obj1(10);
  ArrayValue obj2, obj3;
  obj3 = obj2 = obj1;
  obj2.print();
  cout<<endl;
  obj3.print();
  return 0;
}

// Chaining (or method chaining):
// A programming technique in which multiple method calls 
// are connected in a single statement. This is made possible 
// when each method returns an object (*this) that can be 
// used to call the next method.
