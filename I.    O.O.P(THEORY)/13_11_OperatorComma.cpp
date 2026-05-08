#include <iostream>
using namespace std;

class MyClass {
private:
    int value;

public:
    MyClass(int val) : value(val) {}

    // Overloading the , operator on the left side of the = operator
    MyClass& operator,(const MyClass& other) {
        value += other.value;
        return *this;
    }

    int getValue() const {
        return value;
    }
};

int main() {
    MyClass obj1(5);
    MyClass obj2(10);

    // Equal operator has higher precedence than comma operator
    //obj1, obj2 = MyClass(3);  // , operator on the left side of =, first execute = and then , 
    
    // Precedence is changed by using parentheses
    (obj1, obj2) = MyClass(3);  // , operator on the left side of =, first run , and then =
    cout << "Result of obj1: " << obj1.getValue() << endl;  // Output: Result: 8 and 3 
    cout << "Result of obj2: " << obj2.getValue() << endl;  // Output: Result: 3 and 10

    return 0;
}
