#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0; // Pure virtual, also enforces runtime binding    
    /*
    virtual void draw() //Remove virtual to make it early/static/compile time binding
    {
        cout<<"Draw a Shape"<<endl;
    }
    */
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing a circle" << endl;
    }
};

class Square : public Shape {
public:
    void draw() {
        cout << "Drawing a square" << endl;
    }
    void display() {
        cout << "Display a square" << endl;
    }
};

int main() {
    Circle c;
    Square s;

    void* shapes[2];    // void* is a typeless pointer in C++
    shapes[0] = &c;
    shapes[1] = &s;

    for (int i = 0; i < 2; i++) {
        ((Shape*)shapes[i])->draw();
    }

    // void* is a generic pointer points to any type of object. However, as 
    // void* has no type information, need explicit casting to correct type 
    // before calling any methods.
    

    Shape* shape = new Square();
    //shape->display();  // error: 'class Shape' has no member named 'display'
    ((Square*)shape)->display();   // Now you need downcasting:

    return 0;
}
