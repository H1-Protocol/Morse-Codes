#include<iostream>
using namespace std;
class MyClass
{
    int x; // Now it is private, to access it we will be using friend function.
    public:
    MyClass() //constructor
    { x=5; }
    
    MyClass(int x) //constructor
    { this->x = x; }

    friend ostream& operator<<(ostream &out, MyClass& obj);
};

ostream& operator<<(ostream &out, MyClass& obj) // Third way: Using friend function
{
        out<<endl<<"Value: "<<obj.x;
}

int main()
{
    MyClass obj1,obj2(10);
    cout<<obj1;   //operator<<(cout, obj1)
    cout<<endl;
    cout<<obj1<<obj2;   //operator<<(operator<<(cout, obj1), obj2) //Nested or Cascading
    return 0;
}