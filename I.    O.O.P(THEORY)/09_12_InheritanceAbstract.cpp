#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0; // Pure virtual, enforces runtime binding
};

class Circle : public Shape {
public:
    void draw() override { // override keyword introduced in C++11 tells compiler that
                           // This function override a virtual function in the base class
        cout << "Drawing a circle" << endl;
    }
};

class Square : public Shape {
public:
    void draw() {
        //Shape::draw(); // if definition also provided
        cout << "Drawing a square" << endl;
    }
};

int main() {
    Circle c;
    Square s;

    Shape* shapes[2];
    shapes[0] = &c;
    shapes[1] = &s;

    for (int i = 0; i < 2; i++) {
        shapes[i]->draw();
    }
    return 0;
}

/*
Even draw() is pure virtual, you can provide a definition in C++ to
forces derived classes to override a function, but still provides a 
default implementation, optionally called using Shape::draw().

void Shape::draw(){     
    cout<<"Drawing Shape"<<endl;
}
*/