#include "globals.h"
#include "GameState.h"

void playMove(GameState& game_state){
    
    //declare variables for easier access
    int row = game_state.get_selectedRow();
    int column = game_state.get_selectedColumn();
    int symbol;
    
    //set which move is about to be made (X or O)
    if(game_state.get_turn())
        symbol = 1;
    else
        symbol = -1;
    
        
    //Check if move is valid
    //tictactoe.cpp already checked if within bounds, just have to check if place is blank
    if(game_state.get_gameBoard(row,column) == 0){
        //move is valid = change boolean
        game_state.set_moveValid(true);
        
        //Change board value
        game_state.set_gameBoard(row, column, symbol);
        
        //Change turn boolean
        if(game_state.get_turn())
            game_state.set_turn(false);
        else
            game_state.set_turn(true);
        
        //determine win code
        if(game_state.get_gameBoard(2,0) == symbol && game_state.get_gameBoard(1,1) == symbol && game_state.get_gameBoard(0,2) == symbol)
            game_state.set_winCode(8);
        else if(game_state.get_gameBoard(0,0) == symbol && game_state.get_gameBoard(1,1) == symbol && game_state.get_gameBoard(2,2) == symbol)
            game_state.set_winCode(7);
        else if(game_state.get_gameBoard(0,2) == symbol && game_state.get_gameBoard(1,2) == symbol && game_state.get_gameBoard(2,2) == symbol)
            game_state.set_winCode(6);
        else if(game_state.get_gameBoard(0,1) == symbol && game_state.get_gameBoard(1,1) == symbol && game_state.get_gameBoard(2,1) == symbol)
            game_state.set_winCode(5);
        else if(game_state.get_gameBoard(0,0) == symbol && game_state.get_gameBoard(1,0) == symbol && game_state.get_gameBoard(2,0) == symbol)
            game_state.set_winCode(4);
        else if(game_state.get_gameBoard(2,0) == symbol && game_state.get_gameBoard(2,1) == symbol && game_state.get_gameBoard(2,2) == symbol)
            game_state.set_winCode(3);
        else if(game_state.get_gameBoard(1,0) == symbol && game_state.get_gameBoard(1,1) == symbol && game_state.get_gameBoard(1,2) == symbol)
            game_state.set_winCode(2);
        else if(game_state.get_gameBoard(0,0) == symbol && game_state.get_gameBoard(0,1) == symbol && game_state.get_gameBoard(0,2) == symbol)
            game_state.set_winCode(1);
        else
            game_state.set_winCode(0);
        
        
        //set gameOver boolean
        
        int remainingMoves=0;
        
        for(int i=0; i<boardSize; i++){
            for (int j=0; j<boardSize; j++){
                if(game_state.get_gameBoard(i,j)== Empty)
                    remainingMoves++;
            }   
        }
     
        if (game_state.get_winCode() != 0)
            game_state.set_gameOver(true);
        else if(remainingMoves==0)
            game_state.set_gameOver(true);
        else
            game_state.set_gameOver(false);
        
        
    }
    else{
        //move is invalid
        game_state.set_moveValid(false);
        
        //all other variables remain unchanged
    }        
        
    
    
    
    //If move is NOT valid, stay in loop
}
