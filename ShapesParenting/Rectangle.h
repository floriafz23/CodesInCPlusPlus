
#ifndef Rectangle_h
#define Rectangle_h

#include <iostream>
#include <string>
using namespace std;


#include "Shape.h"

class Rectangle : Shape {
private:
    float width;                  // The width of the circle
    float height;                 // The height of the circle

public:
    // Constructor
    Rectangle (string n, float xcent, float ycent, float width, float height);
    
    // Destructor
    virtual ~Rectangle();
    
    // Accessor
    float getWidth() const;       // Returns the width of the circle
    float getHeight() const;       // Returns the height of the circle

    // Mutator
    void setWidth(float r);       // Sets the width of the circle
    void setHeight(float r);       // Sets the height of the circle
    
    // Utility methods
    virtual void draw() const;     // Draws the rectangle; for the assignment it
                                   // prints the information of the circle
    
    virtual float computeArea() const;   // Computes the area of the circle
    
    virtual Shape* clone() const;  // Clones the object
};


#endif /* Rectangle_h */


