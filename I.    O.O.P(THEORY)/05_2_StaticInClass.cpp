#include<iostream>
using namespace std;

class Student { 
	public:
	

	Student(){
		counter++;
		name = "Not Set";
	}
	~Student(){
		counter--;
		cout<<"-----------Counter Value-----------: "<<counter<<endl;
	}

		string name;
		static int counter; 
		//static int counter=0; // ISO C++ forbids in-class initialization of non-const static member
};

int Student::counter = 0;
//int Student::counter; // Also correct

void method(){
	Student std4; 
	cout<<"Counter Value (method): "<<std4.counter<<endl; 
}

int main() 
{ 
	//Student::counter = 1; // Allowed 
	cout<<"Counter Value: "<<Student::counter<<endl; 
	Student std1; 
	cout<<"Counter Value: "<<std1.counter<<endl;
	  //OR
	cout<<"Counter Value: "<<Student::counter<<endl; 

	Student std2;
	cout<<"Counter Value: "<<std2.counter<<endl; 
	
	Student std3;
	cout<<"Counter Valu3: "<<std3.counter<<endl; 
	
	method();
	cout<<"Counter Value: "<<std1.counter<<endl; 

	return 0; 
} 