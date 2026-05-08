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
	//virtual ~A(){
	~A(){
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
	//virtual ~B(){ // Making is virtual will resolve the issue, and late binding will be done.
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
	objParameter.fun1(); // This will call fun1() of Class C, as refence type is of Class B, but fun1() is virtual in parent Class B
	objParameter.fun2(); // This will call fun2() of Class C, as refence type is of Class B, but fun2() is virtual in parent Class B through A
	objParameter.fun3(); // This will call fun3() of Class B, as refence type is of Class B as well as fun3() is not virtual in parent Class B
}

int main(){
	C objC;
	outFun(objC);
	B *p = new C(); // or B *p = new C; in case of default () not required
	delete p; // Destructor of B will be called, as destructor of parent Class B in not virtual. Further, B is inherited from A, so destructor of A will be called.
    cout<<sizeof(C); // Making method/s virtual will increase the size by 4 bytes in 32 bit reference
    return 0; 
    // Here objC becoming out of scope, so the destructor of C will be called, as C inherited from B, so B's destructor will be called
    // Finally, B is inherited from A, so A's destructor will be called.
}

//fun2() is declared as virtual in class A. When a function is declared as virtual in a base class, 
// it is considered virtual in all derived classes, even if it is not explicitly declared as virtual 
// in those derived classes. So, in class B, when it overrides fun2(), it implicitly becomes virtual 		