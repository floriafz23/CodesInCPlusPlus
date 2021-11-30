#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "globals.h"
#include "Shape.h"
#include "ShapeNode.h"
#include "GroupNode.h"
#include "ShapeList.h"
#include "GroupList.h"

bool nameValid(string name);
bool nameFree(string name);
void create_shape(stringstream & sin);
void create_group(stringstream & sin);
void move_shape(stringstream & sin);
void draw_element();
void delete_element(stringstream & sin);

// This is a pointer to the groups list
// The list itseld must be allocated
GroupList* gList;

// ECE244 Student: you may want to add the prototype of
// helper functions you write here

int main() {
    
    // Create the groups list
    gList = new GroupList();
    
    // Create the pool group and add it to the group list
    GroupNode* poolGroup = new GroupNode(keyWordsList[NUM_KEYWORDS-1]);
    gList->insert(poolGroup);
    
    string line;
    string command;
    bool has_errors = false;
    
    cout << "> ";         // Prompt for input
    getline(cin, line);    // Get a line from standard input

    while ( !cin.eof () ) {
        // Put the line in a linestream for parsing
        // Making a new sstream for each line so flags etc. are cleared
        
        stringstream lineStream (line);
        
        
        // Read from string stream into the command
        // The only way this can fail is if the eof is encountered
        lineStream >> command;

        // Check for the command and act accordingly
        if(command == "shape")
            create_shape(lineStream);
        else if(command == "group")
            create_group(lineStream);
        else if(command == "move")
            move_shape(lineStream);
        else if(command == "draw")
            draw_element();
        else if(command == "delete")
            delete_element(lineStream);

                    
        // Once the command has been processed, prompt for the
        // next command
        
        command = "";
        line = "";
        
        cout << "> ";          // Prompt for input
        getline(cin, line);
        
    }  // End input loop until EOF.
    
    delete gList;
    gList = nullptr;
    
    return 0;
}

bool nameValid(string name){
    bool error_free = true;
    
    // Check for invalid name
    for(int i=0; i<(NUM_KEYWORDS); i++){
        if(name == keyWordsList[i])
            error_free = false;
    }
    for(int i=0; i<(NUM_TYPES); i++){
        if(name == shapeTypesList[i])
            error_free = false;
    }
    if(!error_free){
        cout << "error: invalid name" << endl;
        return error_free;
    }
    
    return error_free;
}

bool nameFree(string name){
    
    bool error_free = true;

    // Check for name "name" exists
    GroupNode* groupFinder = gList->getHead();
    ShapeNode* shapeFinder = nullptr;

    while((groupFinder != nullptr)){
        if(groupFinder->getName() == name || shapeFinder != nullptr)
            break;
        else{
            shapeFinder = groupFinder->getShapeList()->find(name);
            groupFinder = groupFinder->getNext();
        }
    }

    if((groupFinder!=nullptr) || (shapeFinder != nullptr)){
        error_free = false;
        cout << "error: name " << name << " exists" << endl;
        return error_free;
    }
    
    return error_free;
    
}

void create_shape(stringstream & sin){
    string name, type;
    int xloc, yloc, xsize, ysize;
        
    sin >> name >> type >> xloc >> yloc >> xsize >> ysize;
    
        
    if(!nameValid(name))
        return;
    else if(!nameFree(name))
        return;
    else{
        Shape* newShape =  new Shape(name, type, xloc, xsize, yloc, ysize);

        ShapeNode* newShapeNode = new ShapeNode();    
        newShapeNode->setShape(newShape);

        gList->getHead()->getShapeList()->insert(newShapeNode);


        cout << name << ": " << type << ' ' << xloc << ' ' << yloc << ' ' << xsize << ' ' << ysize << endl;
    }

}

void create_group(stringstream & sin){
    string name;
    
    sin >> name;
    if(!nameValid(name))
        return;
    else if(!nameFree(name))
        return;
    else{

        GroupNode* newGroup = new GroupNode(name);

        gList->insert(newGroup);


        cout << name << ": group" << endl;
    }

}

void move_shape(stringstream & sin){
    string name1, name2;
    string printing = "";
    
    sin >> name1 >> name2 >> printing;
    
    if(!nameValid(name1))
        return;
    if(!nameValid(name2))
        return;
    
    
    //Check for shape name exists
    GroupNode* shapeGroupFinder = gList->getHead();
    ShapeNode* shapeFinder = nullptr;

    while((shapeGroupFinder != nullptr)){
        if(shapeFinder != nullptr){
            break;
        }
        else{
            shapeFinder = shapeGroupFinder->getShapeList()->find(name1);
            if(shapeFinder ==nullptr)
                shapeGroupFinder = shapeGroupFinder->getNext();
        }
    }
        
    //Check for group name exists
    GroupNode* groupFinder = gList->getHead();

    while(groupFinder != nullptr){
        if(groupFinder->getName() == name2)
            break;
        groupFinder = groupFinder->getNext();
    }
    
    if(shapeFinder == nullptr)
        cout << "error: shape " << name1 << " not found" << endl;
    else if(groupFinder == nullptr)
        cout << "error: group " << name2 << " not found" << endl;
    else{
        ShapeNode* removedNode = shapeFinder;
        
        removedNode = shapeGroupFinder->getShapeList()->remove(name1);
        removedNode->setNext(nullptr);
        
        groupFinder->getShapeList()->insert(removedNode);
        
        if(printing == "")
            cout << "moved " << name1 << " to " << name2 << endl;
    }
   
    
}

void draw_element(){
    cout << "drawing:" << endl;
    gList->print();
}

void delete_element(stringstream & sin){
    string name;
    
    sin >> name;
    
    if(!nameValid(name))
        return;
        
    //Check for name exists
    GroupNode* groupFinder = gList->getHead();
    ShapeNode* shapeFinder = nullptr;
    GroupNode* shapeGroupFinder = groupFinder;

    while((groupFinder != nullptr)){
        if(groupFinder->getName() == name || shapeFinder != nullptr)
            break;
        else{
            shapeFinder = groupFinder->getShapeList()->find(name);
            shapeGroupFinder = groupFinder;
            groupFinder = groupFinder->getNext();
        }
    }
   
    
    
     if(shapeFinder !=nullptr){
        ShapeNode* removedNode = shapeFinder;
        
        removedNode = shapeGroupFinder->getShapeList()->remove(name);
        delete removedNode;
        cout << name << ": deleted" << endl;
    }
    else if(groupFinder !=nullptr){
        
        ShapeNode* groupNodes = groupFinder->getShapeList()->getHead();
        groupFinder->getShapeList()->setHead(nullptr);
        
        gList->getHead()->getShapeList()->insert(groupNodes);

        GroupNode* removedGroup = gList->remove(name);
        
        delete groupFinder;
        cout << name << ": deleted" << endl;
    }
    else
        cout << "error: shape " << name << " not found" << endl;
 
    
}

