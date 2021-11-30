#ifndef globals_h
#define globals_h
#endif

#include "globals.h"
#include "Shape.h"
using namespace std;



Shape::Shape(string n, string t, int x_loc, int x_sz, int y_loc, int y_sz){
    name = n;
    type = t;
    x_location = x_loc;
    x_size = x_sz;
    y_location = y_loc;
    y_size = y_sz;
}

// Accessors

//Returns type
string Shape::getType(){
    return type;
}

//Returns name
string Shape::getName(){
    return name;
}

//Returns location on x-axis
int Shape::getXlocation(){
    return x_location;
}

//Returns location on y-axis
int Shape::getYlocation(){
    return y_location;
}

//Returns size in x-dimension
int Shape::getXsize(){
    return x_size;
}

//Returns size in y-dimension
int Shape::getYsize(){
    return y_size;
}

// Mutators

//Sets type
void Shape::setType(string t){
    
}      // Sets the type (see globals.h)
                               // No error checking done inside the method
                               // The calling program must ensure the type
                               // is correct

//Sets name
void Shape::setName(string n){
    name = n;
}

//Sets location on x-axis
void Shape::setXlocation(int x_loc){
    x_location = x_loc;
}

//Sets location on y-axis
void Shape::setYlocation(int y_loc){
    y_location = y_loc;
}

//Sets size in x-dimension
void Shape::setXsize(int x_sz){
    x_size = x_sz;
}
//Sets size in y-dimension
void Shape::setYsize(int y_sz){
    y_size = y_sz;
}

// Sets rotation of shape
void Shape::setRotate(int angle){
    rotation = angle;
}

// Utility methods
void Shape::draw(){
    cout << name << ": " << type << ' ' << x_location << ' ' << y_location << ' ' << x_size << ' ' << y_size << endl;
}                   // Draws a shape; for this assignment it
                               // only prints the information of the shape

