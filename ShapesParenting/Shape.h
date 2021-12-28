//
//  File Shape.h provided by Professor Tarek Abdelrahman of University of Toronto
//

#ifndef Shape_h
#define Shape_h

#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
    string name;                   // The name of the shape
    float x_centre;                // The centre of the shape on the x-axis
    float y_centre;                // The centre of the shape on the y-axis

   // Constructor is protected, so it can only be invoked from derived shape
   // classes as part of building a derived object. No other classes can
   // create a Shape anyway, since it is an abstract base class
   Shape (string n, float xcent, float ycent);

public:
    // Accessors
    string getName() const;                // Returns the name of the shape
    float getXCentre() const;              // Returns centre of the shape on the x-axis
    float getYCentre() const;              // Returns centre of the shape on the y-axis

    // Mutators
    void setName(string n);                // Sets the name of the shape
    void setXCentre(float xcent);          // Sets centre of the shape on the x-axis
    void setYCentre(float ycent);          // Sets centre of the shape on the y-axis
    
    // Utility methods
    virtual void draw() const = 0 ;        // Draws a shape; for the assignment it
                                           // prints the information of the shape
    
    virtual float computeArea() const = 0; // Computes the area of the shape
    
    virtual ~Shape();                      // Virtual destructor
    
    virtual Shape* clone() const = 0;      // This method clones the object
};

#endif /* Shape_h */


