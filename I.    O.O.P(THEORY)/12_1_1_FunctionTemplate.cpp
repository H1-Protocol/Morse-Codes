#include<iostream>
using namespace std;

// Telling compiler maxVal() is a function template and T is a 
// template parameter uses in function's parameter list, return and body.
template <class T>
//template <typename T> //both used i.e class or typename
T maxVal(T a, T b){
  if(a > b)
    return a;
  else
    return b;
}

int main(){
  cout<<"Maximum Values: "<<endl;
  cout<<maxVal(5,7)<<endl;
  cout<<maxVal(5.8,5.7)<<endl;
  cout<<maxVal("Ali","Ahmad")<<endl;
  return 0;
}
