
#ifndef Triangle_h
#define Triangle_h

#include <iostream>
#include <string>
using namespace std;

#include "Shape.h"

class Triangle : Shape {
private:
    float x1;  
    float y1; 
    float x2;  
    float y2; 
    float x3;  
    float y3; 

public:
    // Constructor
    Triangle (string n, float x1, float y1, float x2, float y2, float x3, float y3);
    
    // Destructor
    virtual ~Triangle();
    
    // Accessor
    float getX1() const;  
    float getY1() const; 
    float getX2() const;  
    float getY2() const; 
    float getX3() const;  
    float getY3() const; 

    // Mutator
    void setX1(float x_1); 
    void setY1(float y_1); 
    void setX2(float x_2); 
    void setY2(float y_2); 
    void setX3(float x_3); 
    void setY3(float y_3); 
    
    // Utility methods
    virtual void draw() const;     // Draws the rectangle; for the assignment it
                                   // prints the information of the circle
    
    virtual float computeArea() const;   // Computes the area of the circle
    
    virtual Shape* clone() const;  // Clones the object
};

#endif /* Triangle_h */


