#include "Shape.h"
#include "ShapeNode.h"
#include "ShapeList.h"
#include "GroupNode.h"

using namespace std;

// Sets group name to n and makes myShapeList point to a new SHapeList, sets next to null
GroupNode::GroupNode(string n){
    name = n;
    myShapeList = new ShapeList();
    next = nullptr;
}

//Deletes the myShapeList list
GroupNode::~GroupNode(){
    
    delete myShapeList;
    myShapeList = nullptr;
}

// Returns group name
string GroupNode::getName() const{
    return name;
}

//Returns myShapeList
ShapeList* GroupNode::getShapeList() const{
    return myShapeList;
}

// Sets myShapeList to give pointer
void GroupNode::setShapeList(ShapeList* ptr){
    myShapeList = ptr;
}

// Returns next
GroupNode* GroupNode::getNext() const{
    return next;
}

// Sets next to given pointer
void GroupNode::setNext(GroupNode* ptr){
    next = ptr;
}

// Prints the GroupNode
void GroupNode::print() const{
    cout << name << ":" << endl;
    myShapeList->print();
}
