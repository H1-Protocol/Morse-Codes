#include<iostream>
using namespace std;

// Telling compiler sum() is also a function template and T is a 
// template parameter uses in function's parameter list and body.
template <class T>
T sum(T a, T b){
  return a + b;
}

int main(){
  cout<<endl<<"Adding/Concatenating Values: "<<endl;
  //char* a = "Ali";    // invalid operands of types 'char*' 
  //char* b = " Ahmad"; // and 'char*' to binary 'operator +'  
  
  // string type support concatenate
  string a = "Ali"; 
  string b = " Ahmad"; 
  
  cout<<sum(a, b)<<endl;
  cout<<sum('A', '1')<<endl; // Ascii of 'A' = 65, and '1' = 49, so 'A' + '1' = 114 (r)
  cout<<sum(6,8)<<endl;

  return 0;
}
