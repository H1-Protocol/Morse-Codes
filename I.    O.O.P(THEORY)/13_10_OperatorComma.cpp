#include <iostream>

class MyClass {
private:
    int value;

public:
    MyClass(int val) : value(val) {}

    // Overloading the , operator as a member function
    MyClass operator,(const MyClass& other) const {
        return MyClass(value + other.value);
    }

    int getValue() const {
        return value;
    }
};

int main() {
    MyClass obj1(5);
    MyClass obj2(10);
   
    MyClass result = (obj1, obj2);  // Using the overloaded , operator
    std::cout << "Result: " << result.getValue() << std::endl;  // Output: Result: 15

    return 0;
}
