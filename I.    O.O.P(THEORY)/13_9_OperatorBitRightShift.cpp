#include <iostream>
using namespace std;

class MyClass {
public:
    int value;

    // Overloaded bitwise left shift operator
    MyClass operator>>(int shift) const {
        MyClass result;
        result.value = value>>shift;
        return result;
    }
};

int main() {
    MyClass obj;
    obj.value = 5;

    // Perform bitwise left shift on the object using the overloaded << operator
    MyClass shiftedObj = obj>>2; // left shift two time

    // Display the original and shifted values
    cout << "Original Value: "<<obj.value<<endl;
    cout << "Shifted Value (two times): "<<shiftedObj.value<<endl;

    return 0;
}
