#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "globals.h"
#include "Shape.h"

// This is the shape array, to be dynamically allocated
Shape** shapesArray;

// The number of shapes in the database, to be incremented 
int shapeCount = 0;

// The value of the argument to the maxShapes command
int max_shapes;

// ECE244 Student: you may want to add the prototype of
// helper functions you write here
bool errors(stringstream & sin);
void create_array(stringstream &sin);
void create_shape(stringstream & sin);
void move_shape(stringstream & sin);
void rotate_shape(stringstream & sin);
void draw_shape(stringstream & sin);
void delete_shape(stringstream & sin);


int main() {

    string line;
    string command;
    bool has_errors = false;
    
    cout << "> ";         // Prompt for input
    getline(cin, line);    // Get maxShapes from keyboard
    stringstream lineStream1(line); // create new stream
    lineStream1 >> command; // store input into different variables
    
    if(command == "maxShapes")
        create_array(lineStream1);
    
    line = "";
    cout << "> ";         // Prompt for input
    getline(cin, line);    // Get command from keyboard
    stringstream lineStream2(line);

    while ( !cin.eof () ) {
        // Put the line in a linestream for parsing
        // Making a new sstream for each line so flags etc. are cleared
        
        stringstream lineStream2(line);
        stringstream lineStream(line);

        //check all errors
        has_errors = !errors(lineStream2);
        if(has_errors)
            goto nextcommand;
        
        lineStream >> command;

        
        // Read from string stream into the command
        // The only way this can fail is if the eof is encountered

        // Check for the command and act accordingly
        
        if(command == "maxShapes")
            create_array(lineStream);
        else if(command == "create")
            create_shape(lineStream);
        else if(command == "move")
            move_shape(lineStream);
        else if(command == "rotate")
            rotate_shape(lineStream);
        else if(command == "draw")
            draw_shape(lineStream);
        else if(command == "delete")
            delete_shape(lineStream);
        
        
        // Once the command has been processed, prompt for the
        // next command
        nextcommand:
        
        line = "";
        cout << "> ";          // Prompt for input
        getline(cin, line);
        
    }  // End input loop until EOF.
    
    return 0;
}

bool errors(stringstream & sin){
    bool error_free = true;
    string command;
    string name = "";
    string type = "";
    string next = "";
    int arg = -7308;
    
    // if input is empty
    
    if(sin.eof()){
        error_free = false;
        cout << "Error: invalid command" << endl;
        return error_free;
    }
    
    // check invalid command
    sin >> command; 
    
    
    error_free = false;
    for(int i=1; i<7;i++){
        if(command == keyWordsList[i]){
            error_free = true;
        }
    }
    
    if(!error_free){
        cout << "Error: invalid command" << endl;
        return error_free;
    }
        // check too few arguments
    if(sin.eof()){
        error_free = false;
        cout << "Error: too few arguments" << endl;
        return error_free;
    }
    
    // check invalid shape name
    if(command == "create"){

        sin >> name;
        
        if(name == ""){
            error_free = false;
            cout << "Error: too few arguments" << endl;
            return error_free;
        }
        
        for(int i=0; i<7; i++){
            if(name == keyWordsList[i])
                error_free = false;
        }
        for(int i=0; i<4; i++){
            if(name == shapeTypesList[i])
                error_free = false;
        }
        if(!error_free){
            cout << "Error: invalid shape name" << endl;
            return error_free;
        }
        
        // check too few arguments
        if(sin.eof()){
            error_free = false;
            cout << "Error: too few arguments" << endl;
            return error_free;
        }
        
    }
    
    // check shape name exists
    
    if(command == "create"){
        for(int i=0; i<shapeCount; i++){
            if(shapesArray[i] !=nullptr){
                string existingName = shapesArray[i]->getName();
                if(name == existingName)
                    error_free = false;
            }
        }
        
        if(!error_free){
            cout << "Error: shape " << name << " exists" << endl;
            return error_free;
        }
        
        // check too few arguments
        if(sin.eof()){
            error_free = false;
            cout << "Error: too few arguments" << endl;
            return error_free;
        }
    }
    
    // check shape name not found
    if((command == "move") || (command == "rotate")){
        bool nameMatch = false;
        
        sin >> name;
        
        if(name == ""){
            error_free = false;
            cout << "Error: too few arguments" << endl;
            return error_free;
        }
        
        for(int i=0; i<shapeCount; i++){
            if(shapesArray[i] !=nullptr){
                if(name == (shapesArray[i])->getName())
                    nameMatch = true;
            }
        }
        
        error_free = nameMatch;
        if(!error_free){
            cout << "Error: shape " << name << " not found" << endl;
            return error_free;
        }
        
        // check too few arguments
        if(sin.eof()){
            error_free = false;
            cout << "Error: too few arguments" << endl;
            return error_free;
        }
        
    }
   
    if((command == "draw") || (command == "delete")){
        bool nameMatch = false;

        sin >> name;
        
        if(name == ""){
            error_free = false;
            cout << "Error: too few arguments" << endl;
            return error_free;
        }
        
        for(int i=0; i<shapeCount; i++){
            if(shapesArray[i] !=nullptr){
                if(name == (shapesArray[i])->getName())
                    nameMatch = true;
            }
        }
        if(name == "all")
            nameMatch = true;
        
        error_free = nameMatch;
        if(!error_free){
            cout << "Error: shape " << name << " not found" << endl;
            return error_free;
        }
    }
    
    // check invalid shape type
    
    if(command == "create"){
        bool typeMatch = false;

        sin >> type;
        
        if(type == ""){
            error_free = false;
            cout << "Error: too few arguments" << endl;
            return error_free;
        }
        
        for(int i=0; i<4;i++){
            if(type == shapeTypesList[i])
                typeMatch = true;
        }
        
        error_free = typeMatch;
        if(!error_free){
            cout << "Error: invalid shape type" << endl;
            return error_free;
        }
        
        // check too few arguments
        if(sin.eof()){
            error_free = false;
            cout << "Error: too few arguments" << endl;
            return error_free;
        }
        
    }
    
    // check invalid argument or invalid value
    string temp_string = sin.str();
    stringstream sin_copy(temp_string);
    
    if((command == "create") || (command == "move") || (command == "rotate" || (command == "maxShapes"))){
        int necessaryArgs;
        if (command == "create")
            necessaryArgs = 4;
        else if (command == "move")
            necessaryArgs = 2;
        else if (command == "rotate")
            necessaryArgs = 1;
        else
            necessaryArgs = 1;
        
        
        
        for(int i=0; i<necessaryArgs; i++){

            sin >> arg;
            
            if(arg == -7308){
                error_free = false;
                cout << "Error: too few arguments" << endl;
                return error_free;
            }
            
            
            // check invalid argument
            if(sin.fail() && !sin.eof()){
                error_free = false;
                cout << "Error: invalid argument" << endl;
                return error_free;
            }
                       
            if((!sin.eof()) && ((sin.peek() != ' ') && (sin.peek() != '\t') && (sin.peek() != EOF))){
                error_free = false;
                cout << "Error: invalid argument" << endl;
                return error_free;
            }
            
            //check invalid value
            
            if(arg < 0){
                error_free = false;
                cout << "Error: invalid value" << endl;
                return error_free;
            }
            if(command == "rotate"){
                if(arg > 360){
                    error_free = false;
                    cout << "Error: invalid value" << endl;
                    return error_free;
                }
            }
            
            if (i != necessaryArgs -1){
                // check too few arguments
                if(sin.eof()){
                    error_free = false;
                    cout << "Error: too few arguments" << endl;
                    return error_free;
                }
            }
            
            arg = -7308;
                
        }
        
        if((command == "create") && (type == "circle")){
            string garbage1, garbage2, garbage3;
            int xloc, yloc, xsize, ysize;
            sin_copy >> garbage1 >> garbage2 >> garbage3 >> xloc >> yloc >> xsize >> ysize;
            
            if(xsize != ysize){
                error_free = false;
                cout << "Error: invalid value" << endl;
                return error_free;
            }
        }
        
    }
    

    // check too many arguments
    sin >> next;

    if (!sin.eof() || (next != "")){
        error_free = false;
        cout << "Error: too many arguments" << endl;
        return error_free;
    }
    
    // check array full
    if(command == "create"){
        if(shapeCount == max_shapes){
            error_free = false;
            cout << "Error: shape array is full" << endl;
            return error_free;
        }
    }
    
    return error_free;
}

void create_array(stringstream &sin){
    if(shapesArray != nullptr){
        for(int i=0; i<max_shapes; i++){
            delete shapesArray[i];
            shapesArray[i] = nullptr;
        }
        delete []shapesArray;
        shapesArray = nullptr;
        shapeCount = 0;
    }
    
    sin >> max_shapes;
    
    shapesArray = new Shape*[max_shapes];
    cout << "New database: max shapes is " << max_shapes << endl;
    
    shapeCount = 0;
}

void create_shape(stringstream & sin){
    string name, type;
    int xloc, yloc, xsize, ysize;
    
    sin >> name >> type >> xloc >> yloc >> xsize >> ysize;
    
    shapesArray[shapeCount] = new Shape(name, type, xloc, xsize, yloc, ysize);
    
    shapeCount++;
    
    cout << "Created " << name << ": " << type << ' ' << xloc << ' ' << yloc << ' ' << xsize << ' ' << ysize << endl;

}

void move_shape(stringstream & sin){
    string name;
    int xloc, yloc;
    int locator;
    
    sin >> name >> xloc >> yloc;
    
    for(int i=0; i< max_shapes; i++){
        if ((shapesArray[i])->getName() == name){
            locator = i;
            break;
        }  
    }
    
    shapesArray[locator]->setXlocation(xloc);
    shapesArray[locator]->setYlocation(yloc);
    
    cout << "Moved " << name << " to " << xloc << ' ' << yloc << endl;

    
}

void rotate_shape(stringstream & sin){
    string name;
    int angle;
    int locator;
    
    sin >> name >> angle;

    cout << "Rotated " << name << " by " << angle << " degrees" << endl;
}

void draw_shape(stringstream & sin){
    string name;
    int locator;
    
    sin >> name;
    
    if(name == "all"){
        cout << "Drew all shapes" << endl;
        for(int i=0; i<shapeCount; i++){
            if(shapesArray[i] !=nullptr)
                (shapesArray[i])->draw();
        }
    }
    else{
        for(int i=0; i< max_shapes; i++){
            if ((shapesArray[i])->getName() == name){
                locator = i;
                break;
            }  
        }
        cout << "Drew ";
        (shapesArray[locator])->draw();
    }
}

void delete_shape(stringstream & sin){
    string name;
    int locator;
    
    sin >> name;
    
    if(name == "all"){
        for(int i=0; i<shapeCount; i++){
            delete shapesArray[i];
            shapesArray[i] = nullptr;
        }
        shapeCount = 0;
        cout << "Deleted: all shapes" << endl;

    }
    else{
        for(int i=0; i< shapeCount; i++){
            if(shapesArray[i] !=nullptr){
                if ((shapesArray[i])->getName() == name){
                    locator = i;
                    break;
                }
            }
        }
        delete shapesArray[locator];
        shapesArray[locator] = nullptr;
        cout << "Deleted shape " << name << endl;
    }    
}
