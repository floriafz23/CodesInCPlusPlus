


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "Shape.h"
#include "Triangle.h"

// Constructor
Triangle::Triangle(string n, float x_1, float y_1, float x_2, float y_2, float x_3, float y_3):Shape(n, ((x_1+x_2+x_3)/3), ((y_1+y_2+y_3)/3)) {
    x1 = x_1;   
    y1 = y_1; 
    x2 = x_2;   
    y2 = y_2; 
    x3 = x_3;   
    y3 = y_3; 
}

// Destructor
Triangle::~Triangle(){
    
}

// Accessors

float Triangle::getX1() const{
    return x1;
}  

float Triangle::getY1() const{
    return y1;
}   

float Triangle::getX2() const{
    return x2;
}  

float Triangle::getY2() const{
    return y2;
}   

float Triangle::getX3() const{
    return x3;
}  

float Triangle::getY3() const{
    return y3;
}   


// Mutator

void Triangle::setX1(float x_1){
    x1 = x_1;
}

void Triangle::setY1(float y_1){
    y1 = y_1;
} 

void Triangle::setX2(float x_2){
    x2 = x_2;
}

void Triangle::setY2(float y_2){
    y2 = y_2;
}    

void Triangle::setX3(float x_3){
    x3 = x_3;
}

void Triangle::setY3(float y_3){
    y3 = y_3;
}    

// Utility methods

// Draws the Triangle; for the assignment it prints the information of the Triangle
void Triangle::draw() const{
        // Set floating point printing to fixed point with 2 decimals
    cout << std::fixed;
    cout << std::setprecision(2);
    
    // Print the information
    cout << "triangle: " << name << " "
         << ((x1+x2+x3)/3) << " " << ((y1+y2+y3)/3)
         << " " << x1 << " " << y1
         << " " << x2 << " " << y2 
         << " " << x3 << " " << y3 << " " << computeArea()
         << endl;
}     

// Computes the area of the circle
float Triangle::computeArea() const{
    float area = (x1 * (y2-y3) + x2 * (y3-y1) + x3 * (y1-y2))/2;
    if(area < 0)
        return (-1*area);
    return area; 
}   

 // Clones the object
Shape* Triangle::clone() const{
    return (new Triangle(*this));
} 


