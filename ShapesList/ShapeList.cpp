#include "Shape.h"
#include "ShapeNode.h"
#include "ShapeList.h"

using namespace std;

// Sets head to nullptr
ShapeList::ShapeList(){
    head = nullptr;
}

// Deletes all list nodes starting with head and associated Shapes
ShapeList::~ShapeList(){
    if(head == nullptr);
    else{
        ShapeNode* currentNode = nullptr;
        ShapeNode* nextNode = head;
        do{
            if(currentNode != nullptr)
                delete currentNode;
            currentNode = nextNode;
            nextNode = nextNode->getNext();
        }while(nextNode != nullptr);
            
        delete currentNode;
        head=nullptr;
    }
}

// Returns the head pointer
ShapeNode* ShapeList::getHead() const{
    return head;
}

// Sets head pointer to given pointer
void ShapeList::setHead(ShapeNode* ptr){
    head = ptr;
}

//Finds shape node with specified shape name, returns pointer to node if found, otherwise returns nullptr
ShapeNode* ShapeList::find(string name) const{
    ShapeNode* finder = head;
    
    //returns null if head is null
    if(finder == nullptr){
        return nullptr;
    }
    
    //search for node with specified shape name
    while(finder != nullptr){
        if(finder->getShape()->getName() == name)
            return finder;
        finder = finder->getNext();
    }
    
    // not found = return null
    return nullptr;
    
}

// Inserts node pointed to by s at the end of the list, s should never be null
void ShapeList::insert(ShapeNode* s){
    if(head == nullptr)
        head = s;
    else{
        ShapeNode* lastFinder = head;
        while(lastFinder->getNext() != nullptr){
            lastFinder = lastFinder->getNext();
        }
        lastFinder->setNext(s);
//        s->setNext(nullptr);
    }
}

// Removes the node with the given shape's name
// Returns a pointer to the removed node or nullptr if node with name dne
ShapeNode* ShapeList::remove(string name){
    if(head == nullptr)
        return nullptr;
    
    ShapeNode* previous = nullptr;
    ShapeNode* finder = head;

    
    while(finder != nullptr){
        if(finder->getShape()->getName() == name)
            break;
        else{
            previous = finder;
            finder = finder->getNext();
        }
    }
    
    // Remove first node
    if(previous == nullptr){
        head = finder->getNext();
        return finder;
    }
    
    // Other cases where node is found
    else if(finder != nullptr){
        previous->setNext(finder->getNext());
        return finder;
        cout << "node is removed" << endl; // DELETE 
    }
    
    // If shape not found
    return nullptr;
    
}

// Prints the list
void ShapeList::print() const{
    if(head == nullptr);
    else{
        ShapeNode* jumper = head;
        while(jumper != nullptr){
            jumper->print();
            jumper = jumper->getNext();
        }
    }
}


