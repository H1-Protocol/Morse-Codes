#include<iostream>
using namespace std;

class MyArray {
public:
    int arr[10];

public:
    MyArray(){
      for(int i=0; i<10; i++){
        arr[i] =  i+1;
      }
    }
    //int operator[](int index) { // a[0] = 888; not possible in the main in this case
    int& operator[](int index) {  // return a value by reference makes a[0] = 888; possible
        if (index < 0 || index >= 10) {
          exit(1);
        }
        return arr[index];
    }
};

int main(){
  MyArray a;
  a[0] = 888; //=>  a.setValue(3, 888);

  for(int i=0; i<10; i++){
    cout<<a[i]<<" ";
  }
  
  int x = a[0];
  cout<<endl<<x;
  return 0;
}
