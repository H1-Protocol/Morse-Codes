#include<iostream>
using namespace std;

class ArrayValue{
public:
  int* values;
  int size;

  ArrayValue(int size){
    this->size = size;
    values = new int[size];
    for(int i=0; i<size; i++){
      values[i] = i + 1;      
    }
  }
  
  ArrayValue(const ArrayValue& other){
    cout<<endl<<"Copy Constructor is called.. ";
    size = other.size;
    values = new int[size];
    for(int i=0; i<size; i++){
      values[i] = other.values[i];      
    }
  }

  void operator=(const ArrayValue& other){
    cout<<endl<<"Opertor= is called.. ";
    size = other.size;
    values = new int[other.size];
    for(int i=0; i<size; i++){
      values[i] =  other.values[i];      
    }
  }

    void print(){
    cout<<endl<<"Valuse are: "<<endl;
    for(int i=0; i<size; i++){
      cout<<this->values[i]<<" ";      
    }
  }

};

int main(){
  ArrayValue obj1(10);
  obj1.values[5] = 66;
  ArrayValue obj2 = obj1; // Calling copy constructor
  obj2.print();
  
  obj1.values[4] = 55; 
  obj2 = obj1; // Calling Assignment Operator
  obj2.print();
  return 0;
}
