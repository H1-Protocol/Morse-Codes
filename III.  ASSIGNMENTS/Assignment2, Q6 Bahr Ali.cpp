#include <iostream>
using namespace std;

class Shape { // Renamed 'shape' to 'Shape' (PascalCase)
private:
    int id; // Renamed 'Id' to 'id' (camelCase)
public:
    Shape(int value) : id(value) { // Using initializer list
        cout << id << " Constructor of Shape" << endl;
    }
    
    // PRACTICE: Added virtual destructor to ensure derived classes are cleaned up
    virtual ~Shape() { cout << "Destructor of Shape" << endl; }
    
    int getId() const { return id; } // Added const
    
    // PRACTICE: Added virtual for polymorphism
    virtual void draw() { 
        cout << id << " Drawing a Shape" << endl;
    }
};

class Triangle : public Shape { // Fixed spelling 'traingle' to 'Triangle'
private: // PRACTICE: Encapsulation (points should be private)
    int* points; 
public:
    Triangle(int value) : Shape(value) {
        points = new int[3];
        cout << getId() << " Constructor of Triangle" << endl;
    }
    ~Triangle() { delete[] points; } // PRACTICE: Clean up memory
    
    void draw() override { // PRACTICE: Added override keyword
        cout << getId() << " Drawing a Triangle" << endl;
    }
};

class Square : public Shape {
private: // PRACTICE: Encapsulation
    int* points;
public:
    Square(int value) : Shape(value) {
        points = new int[4];
        cout << getId() << " Constructor of Square" << endl;
    }
    ~Square() { delete[] points; } // PRACTICE: Clean up memory
    
    void draw() override { 
        cout << getId() << " Drawing a Square" << endl;
    }
};

// PRACTICE: Use reference to base class to allow polymorphism
void drawShape(Shape& s) { 
    s.draw();
}

int main() {
    // PRACTICE: Using polymorphism via pointers to base class
    Shape* sh = new Shape(1);
    Shape* tr = new Triangle(2);
    Shape* sq = new Square(3);

    drawShape(*sh);
    drawShape(*tr);
    drawShape(*sq);

    // PRACTICE: Clean up heap memory
    delete sh; delete tr; delete sq;
    return 0;
}