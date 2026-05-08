#include <iostream>
using namespace std;

// Function declaration
long long factorial(int);
//long long factorial(int n);

int main() {
    int number = 5;
    cout<<"Factorial of "<<number<<" = "<<factorial(number)<<endl;
    return 0;
}

// Function definition
long long factorial(int n) {
    // Base case: factorial of 1 is 1
    if (n <= 1) {
        return 1;
    } else {
        // Recursive case: n! = n * (n-1)!
        return n * factorial(n - 1);
    }
}
