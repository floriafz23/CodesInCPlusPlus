#include "Shape.h"
#include "ShapeNode.h"
#include "ShapeList.h"
#include "GroupNode.h"
#include "GroupList.h"


using namespace std;

//Sets head to nullptr
GroupList::GroupList(){
    head = nullptr;
}

//Deletes all list nodes, including all ShapeList attached to each GroupNode
GroupList::~GroupList(){
    if(head == nullptr);
    else{
        GroupNode* currentNode = nullptr;
        GroupNode* nextNode = head;
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

//Returns the head pointer
GroupNode* GroupList::getHead() const{
    return head;
}

// Sets head pointer to given pointer
void GroupList::setHead(GroupNode* ptr){
    head = ptr;
}

// Inserts the node pointed to by s at the end of the list
void GroupList::insert(GroupNode* s){
    
    if(head == nullptr)
        head = s;
    else{
        GroupNode* lastFinder = head;
        while(lastFinder->getNext() != nullptr){
            lastFinder = lastFinder->getNext();
        }
        lastFinder->setNext(s);
//        s->setNext(nullptr);
    }
}
// Removes group with name "nhame" from list
// Returns pointer to removed node, returns nullptr if name isn't found
GroupNode* GroupList::remove(string name){
    if(head == nullptr)
        return nullptr;
    
    GroupNode* previous = nullptr;
    GroupNode* finder = head;

    
    while(finder != nullptr){
        if(finder->getName() == name)
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
    }
    
    // If shape not found
    return nullptr;
}

// Prints list, one GroupNode at a time
void GroupList::print() const{
    if(head == nullptr);
    else{
        GroupNode* jumper = head;
        while(jumper != nullptr){
            jumper->print();
            jumper = jumper->getNext();
        }
    }
}




