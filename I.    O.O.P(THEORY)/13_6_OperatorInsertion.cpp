#include<iostream>
using namespace std;

class MyClass
{
    public:
    int x; // If we make this private, then cannot be accessed in the global function.
    MyClass(){ //constructor
        x=5;
    }
    MyClass(int x){ //constructor
        this->x=x;
    }
    
    // Using member function of the class (Reverse logic, not commonly used)
    ostream& operator<<(ostream& out){ // (Called as obj << cout; reversed logic)
        out<<endl<<"Value: "<<x;
        return out;
    }
};

ostream& operator<<(ostream &out, MyClass& obj) 
{
        out<<endl<<"Value: "<<obj.x;
        //return out; // Still works, if removed this line, as C++ usually returns reference to passed argument
}

int main()
{
    MyClass obj1, obj2(10);
    cout<<obj1;   //operator<<(cout, obj1)
    
    // As in the above case, the overloaded method cannot be inside MyClass, as cout 
    // itself an object, so we need to overload the method inside ostream, which is 
    // not possible for us to overload the method there. So we have to define the 
    // method global (non-member) function.
    // Two ways to define global methods
        //1. Using normal global function (Not preferred, only possible when all data 
             // members are public)
        //2. Using member function of the class (Reverse logic, not commonly used for 
            // cout << obj as it changes the natural left-to-right stream flow and forces 
            // usage like obj << cout, which is opposite to standard C++ convention.)
        //3. Using the friend function (Preferred, as friend member also access 
            // private data members)

    cout<<obj1<<obj2;   // operator<<(operator<<(cout, obj1), obj2) //Nested or Cascading
                        // Nested implementation done from left to right. 
    
    obj1 << cout; // 2. way, not preferred as it changes the natural left-to-right stream flow  
    return 0;
}