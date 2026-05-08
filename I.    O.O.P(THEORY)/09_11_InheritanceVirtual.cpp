#include <iostream>
using namespace std;

class A{
    public:
	void fun1() {
		cout<<"Fun1 of Class A\n";
	}
	virtual void fun2() {
		cout<<"Fun2 of Class A\n";
	}
	void fun3() {
		cout<<"Fun3 of Class A\n";
	}
	virtual ~A(){
		cout<<"Desctructor of A\n";
	}
};

class  B: public A{
    public:
	virtual void fun1() {
		cout<<"Fun1 of Class B\n";
	}
	void fun2() {
		cout<<"Fun2 of Class B\n";
	}
	void fun3() {
		cout<<"Fun3 of Class B\n";
	}
	~B(){
		cout<<"Desctructor of B\n";
	}
};

class  C: public B{
    public:
	void fun1() {
		cout<<"Fun1 of Class C\n";
	}
	void fun2() {
		cout<<"Fun2 of Class C\n";
	}
	virtual void fun3() {
		cout<<"Fun3 of Class C\n";
	}
	~C(){
		cout<<"Desctructor of C\n";
	}
};

void outFun(B &objParameter){
	objParameter.fun1();
	objParameter.fun2();
	objParameter.fun3();
}

int main(){
	C objC;
	outFun(objC);
	B *p = new C();
	delete p; 
    cout<<sizeof(C); 
    return 0; 
}