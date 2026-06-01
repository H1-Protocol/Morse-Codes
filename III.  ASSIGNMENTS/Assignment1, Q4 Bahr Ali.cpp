#include <iostream>
#include <stdexcept>
using namespace std;

class Time{
    public:
    int h,m,s;

    Time(int h, int m, int s):h(h), m(m), s(s) {
        if (m > 60 || s > 60) {
            throw invalid_argument("No Clock Exceeds 60mph!!!!!!");
        }
    }   
    void print(){
        cout <<h<<"h:"<<m<<"m:"<<s<<"s"<<endl;
    }

    Time operator+(const Time& t){
        return Time(h+t.h,m+t.h,s+t.s);
    }
    Time operator-(const Time& t){
        return Time(h-t.h,m-t.h,s-t.s);
    }
};

int main(){

    try{
Time t1(85,40,40);
Time t2(3,3,3);

Time resultAdd = t1+t2;
resultAdd.print();
cout<<endl;
Time resultSubb = t1-t2;
resultSubb.print();
}
catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }



return 0;
}