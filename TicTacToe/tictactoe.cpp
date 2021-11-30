#include <iostream>
#include <string>
using namespace std;

#include "globals.h"
#include "GameState.h"

// Function prototype for playMove
void playMove(GameState&);

// The main function
int main() {
    
    /**********************************************************************************/
    /* Create an initialized game state object                                        */
    /**********************************************************************************/
    GameState game_state;
    
  

    // Read two integers from the user that represent the row and column
    // the player would like to place an X or an O in
    // You can assume there will be no formatting errors in the input

    int row;
    int col;
    while (!game_state.get_gameOver()) {
        cout << "Enter row and column of a grid cell: ";
        cin >> row >> col;
        
        // Check that the read row and column values are valid grid coordinates
        if ( (row < 0) || (row > 2) || (col < 0) || (col > 2) ) {
            cout << "Invalid board coordinates " << row << " " << col << endl << endl;
           continue;
        }
        else{
            // The coordinates are valid; set the selectedRow and selectedColumn
            // members of the game state to the read values
            
            cout << "Selected row " << row << " and column " << col << endl;

            game_state.set_selectedRow(row);
            game_state.set_selectedColumn(col);
            
            //set moveValid to false & create while loop that runs as long as moveValid is false
            game_state.set_moveValid(false);
            
            
            //Call playMove
            playMove(game_state);

            //print results
            cout << "Game state after playMove:" << endl;
            cout << "Board:" << endl;

            // print out the board
            for(int i=0; i<boardSize; i++){
                cout << "   " ;
                for(int j=0; j<boardSize; j++){
                    if(game_state.get_gameBoard(i,j) == X)
                        cout << "X ";
                    else if (game_state.get_gameBoard(i,j) == O)
                        cout << "O ";
                    else if (game_state.get_gameBoard(i,j) == Empty)
                        cout << "B ";               
                }
                cout << endl;
            }

            cout << "moveValid: " ;
            if(game_state.get_moveValid())
                cout << "true" << endl;
            else
                cout << "false" << endl;

            cout << "gameOver: " ;
            if(game_state.get_gameOver())
                cout << "true" << endl;
            else
                cout << "false" << endl;

            cout << "winCode: " << game_state.get_winCode() << endl << endl;
                
            

        }
        
        
        // Again, the corresponding mutators of GameState must be first
        // implemented before this works
            
        // ECE244 Student: add your code here
            
        // Call playMove
            
        // ECE244 Student: add your code here
            
        // Print the GameState object, as prescribed in the handout
            
        // ECE244 Student: add your code here
            
    }
    

    return 0;
}

