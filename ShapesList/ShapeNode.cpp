#include "Shape.h"
#include "ShapeNode.h"
using namespace std;

// Constructor taking no arguments
ShapeNode::ShapeNode(){
    myShape = nullptr;
    next = nullptr;
}

// Destructor
ShapeNode::~ShapeNode(){
    delete myShape;
}

// Returns myShape
Shape* ShapeNode::getShape() const{
    return myShape;
}

// Sets myShape to given pointer
void ShapeNode::setShape(Shape* ptr){
    myShape = ptr;
}

//Returns next
ShapeNode* ShapeNode::getNext() const{
    return next;
}

// Sets next to given pointer
void ShapeNode::setNext(ShapeNode* ptr){
    next = ptr;
}

// Prints Shapenode
void ShapeNode::print() const{
    myShape->draw();
    
}
