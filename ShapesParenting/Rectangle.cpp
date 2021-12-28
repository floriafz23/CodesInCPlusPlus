
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "Shape.h"
#include "Rectangle.h"

// Constructor
Rectangle::Rectangle(string n, float xcent, float ycent, float w, float h):Shape(n, xcent, ycent) {
    width = w;   
    height = h; 
}

// Destructor
Rectangle::~Rectangle(){
    
}

// Accessors

// Returns the width of the circle
float Rectangle::getWidth() const{
    return width;
}  

// Returns the height of the circle
float Rectangle::getHeight() const{
    return height;
}   

// Mutator

// Sets the width of the circle
void Rectangle::setWidth(float w){
    width = w;
}

// Sets the height of the circle      
void Rectangle::setHeight(float h){
    height = h;
}    

// Utility methods

// Draws the rectangle; for the assignment it prints the information of the rectangle
void Rectangle::draw() const{
        // Set floating point printing to fixed point with 2 decimals
    cout << std::fixed;
    cout << std::setprecision(2);
    
    // Print the information
    cout << "rectangle: " << name << " "
         << x_centre << " " << y_centre
         << " " << width << " " << height << " " << computeArea()
         << endl;
}     

// Computes the area of the circle
float Rectangle::computeArea() const{
    return (width * height);
}   

 // Clones the object
Shape* Rectangle::clone() const{
    return (new Rectangle(*this));
} 

