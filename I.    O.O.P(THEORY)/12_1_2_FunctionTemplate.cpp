#include<iostream>
using namespace std;

// Using more than one templates
template <class S, class T>
T maxVal(S a, T b){
  if(a > b)
    return a;
  else
    return b;
}

int main(){
  cout<<"Maximum Values: "<<endl;
  cout<<maxVal(5,7)<<endl;
  cout<<maxVal(5.8,5)<<endl;
  cout<<maxVal(5,5.8)<<endl;
  cout<<maxVal("Ali","Ahmad")<<endl;
  return 0;
}
