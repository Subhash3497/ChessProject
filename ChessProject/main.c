//Subhash Naidu su162541
//Sean S. COP 3502
//Assignment 1 - ChessMoves

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ChessMoves.h"

                                                                        // Function Prototypes
void checkPiece(char *tok, Move *x);
void checkFrom( char *tok, Move *x);
void checkTo(char *tok, Move *x);

char **createChessBoard(void)
{
    int rows = 8;
    int columns = 8;
    int i,j;
    
    char **board = (char **) malloc(rows * sizeof(char *));               //Dynamic allocation of Chess board
    
    for (i = 0; i < rows; i++)
        board[i] = (char *) malloc(columns * sizeof(char));
    
    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
            if (i == 1)
            {
                for (j = 0; j < 8; j++)
                    board[i][j] = 'P';
            }
            else if (i == 6)
            {
                for (j = 0; j < 8; j++)
                    board[i][j] = 'p';
            }
            else if (i == 0)
            {
                strcpy(board[0],"RNBQKBNR");
            }
            else if (i == 7)
            {
                strcpy(board[7],"rnbqkbnr");
            }
            else
            {
                board[i][j] = ' ';
            }
    if (board == NULL)
    {
        return NULL;
    }
    else
    {
        return board;
    }
}

char **destroyChessBoard(char **board)                              //Freeing Dynamic Memory Allocated for the Chess board.
{
    int i;
    for (i = 0; i < 8; i++)
    {
        free(board[i]);
    }
    free(board);
    
    return NULL;
}

void printChessBoard(char **board)
{
    int i,j;
    
    printf("========\n");
    
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {                                                           //For loop to impliment printing of the chess board to the screen.
            printf("%c",board[i][j]);
        }
        printf("\n");
    }
    printf("========\n\n");
}

char **playTheGame(Game *g)
{
    char **board = createChessBoard();
    printChessBoard(board);
    Move *white = NULL;
    Move *black = NULL;
    int i;
    
    for (i = 0; i < g->numMoves; i++)                               // This loop parses the white move, moves the piece on the board, then prints the board, then parses the black
    {                                                               // move, then moves the piece on the board then prints the board.
        parseNotationString(*g->moves , white, black);
        movePiece(board, white);
        printChessBoard(board);
        movePiece(board, black);
        printChessBoard(board);
    }
    
    
    return board;
}

void checkPiece(char *tok, Move *x)                                 // This is an auxiliary function that I created to check for the type of Piece
{                                                                   // in the parse notation function.
    int i = 0;
    while (i < strlen(tok))                                         // I tokenized the string in parseNotation and passed by refrence to this
    {                                                               // function.
        if (tok[i] == 'R')
        {
            x->piece = 'R';                                         // I know the break statements and the use of multiple ifs instead of else ifs
            break;                                                  // are wierd, but this was the only way i could make it work.
        }
        if (tok[i] == 'N')
        {
            x->piece = 'N';
            break;
        }
        if (tok[i] == 'B')
        {
            x->piece = 'B';
            break;
        }
        if (tok[i] == 'Q')
        {
            x->piece = 'Q';
            break;
        }
        if (tok[i] == 'K')
        {
            x->piece = 'K';
            break;
        }
        else
        {
            x->piece = 'P';
            break;
        }
        
    }
    
    
    
}

void checkFrom( char *tok, Move *x)                                     // This is an auxiliary function that parses the from location information that
{                                                                   // is passed in via refrence from parseNotation.
    int i;

                                                                    //Parses the column information
    x->from_loc.col = 'x';                                          // sets the default value to x if nothing is found.
    
    for (i = 0; i < (strlen(tok) - 2); i++)
    {
        if (tok[i] == 'a'){
            x->from_loc.col = 'a';
        }
        else if (tok[i] == 'b'){
            x->from_loc.col = 'b';
        }
        else if (tok[i] == 'c'){
            x->from_loc.col = 'c';
        }
        else if (tok[i] == 'd'){
            x->from_loc.col = 'd';
        }
        else if (tok[i] == 'e'){
            x->from_loc.col = 'e';
        }
        else if (tok[i] == 'f'){
            x->from_loc.col = 'f';
        }
        else if (tok[i] == 'g'){
            x->from_loc.col = 'g';
        }
        else if (tok[i] == 'h'){
            x->from_loc.col = 'h';
        }
    }
    
                                                                    //Parses the row information
    x->from_loc.row = -1;                                           // sets the default value of -1 if no info is found.
    
    
    for (i = 0; i < (strlen(tok) - 2); i++)
    {
        if (tok[i] == '1')
        {
            x->from_loc.row = 1;
        }
        else if (tok[i] == '2')
        {
            x->from_loc.row = 2;
        }
        else if (tok[i] == '3')
        {
            x->from_loc.row = 3;
        }
        else if (tok[i] == '4')
        {
            x->from_loc.row = 4;
        }
        else if (tok[i] == '5')
        {
            x->from_loc.row = 5;
        }
        else if (tok[i] == '6')
        {
            x->from_loc.row = 6;
        }
        else if (tok[i] == '7')
        {
            x->from_loc.row = 7;
        }
        else if (tok[i] == '8')
        {
            x->from_loc.row = 8;
        }
    }
}

void checkTo(char *tok, Move *x)                                     // This is an auxiliary function that parses the to location information
{                                                                   //  that is passed in via refrence from parseNotation.
    
                                                                    //Parses the Column information.
    int i;
    
    x->to_loc.col = 'x';                                            //Sets default value to x if no column information is found.
    
    for (i = 0; i < strlen(tok); i++)
    {
        if (tok[i] == 'a'){
            x->to_loc.col = 'a';
        }
        else if (tok[i] == 'b'){
            x->to_loc.col = 'b';
        }
        else if (tok[i] == 'c'){
            x->to_loc.col = 'c';
        }
        else if (tok[i] == 'd'){
            x->to_loc.col = 'd';
        }
        else if (tok[i] == 'e'){
            x->to_loc.col = 'e';
        }
        else if (tok[i] == 'f'){
            x->to_loc.col = 'f';
        }
        else if (tok[i] == 'g'){
            x->to_loc.col = 'g';
        }
        else if (tok[i] == 'h'){
            x->to_loc.col = 'h';
        }
    }
    
    
    x->to_loc.row = -1;                                             //Sets default value to -1 if no row infromation is found
                                                                    // parses the row information
    for (i = 0; i < strlen(tok); i++)
    {
        if (tok[i] == '1')
        {
            x->to_loc.row = 1;
        }
        else if (tok[i] == '2')
        {
            x->to_loc.row = 2;
        }
        else if (tok[i] == '3')
        {
            x->to_loc.row = 3;
        }
        else if (tok[i] == '4')
        {
            x->to_loc.row = 4;
        }
        else if (tok[i] == '5')
        {
            x->to_loc.row = 5;
        }
        else if (tok[i] == '6')
        {
            x->to_loc.row = 6;
        }
        else if (tok[i] == '7')
        {
            x->to_loc.row = 7;
        }
        else if (tok[i] == '8')
        {
            x->to_loc.row = 8;
        }
        
    }
    
    
    
    
    
    
}

void parseNotationString(char *str, Move *whiteMove, Move *blackMove)
{
    char *input_data;
    input_data = malloc(sizeof(char)*strlen(str));                  // Dynamically allocated the input data string which stores all the algebric
    strcpy(input_data, str);                                        //  chess notation from the main function
    char *token;
    int i = 0;
    
    
    token = strtok(input_data, " ");                                //tokenize string
    token = strtok((NULL)," ");
    whiteMove->color = 1;                                            // sets known color informaiton
    
    
    while (i < strlen(token))                                           // Parses the is isCapture information
    {
        if (token[i] == 'x')
            whiteMove->isCapture = 1;
        i++;
        
    }                                                               // White Move function Calls
    checkPiece(token, whiteMove);                                   // calls the aux function that checks the piece information.
    checkFrom(token, whiteMove);                                    // calls the aux function that checks the fromLocation information
    checkTo(token, whiteMove);                                      // calls the aux function that checks the toLocation information
    
    token = strtok((NULL)," ");                                     // Tokenizes the next part of the string which contains the Black piece info.
    
    while (i < strlen(token))
    {
        if (token[i] == 'x')                                        // Parses the isCapture information
            blackMove->isCapture = 1;
        i++;
    }
                                                                    // Black Moves function calls
    checkPiece(token, blackMove);                                   // calls the aux function that checks the piece information.
    checkFrom(token, blackMove);                                    // calls the aux function that checks the fromLocation information.
    checkTo(token, blackMove);                                      // calls the aux function that checks the toLocation information.
    
}

void movePiece(char **board, Move *move)
{
    char *y = NULL;                                                     // Theses variables hold the various to and from information that is passed from the move struct.
    char *toy = NULL;                                                   // toy holds the to loc col information, tox holds the to loc row information.
    int x;                                                              // transfx holds the translated from information. By translated i translated from algebreic chess notation to
    int tox;                                                            // array coordinates.
    int transfx;                                                        // transtx and transty is translated to loc information.
    int transfy;
    
    int transtx;
    int transty;
    char *pieceinfo;
    
    
    
    if(move->from_loc.col == 'x' || move->from_loc.row == -1)           // checks to see if there is any from location information. If there is this if statement translates the info
    {                                                                   // to array coordinated and moves the piece to the appropriate location.
        findFromLoc(board, move);                                       // Calls the FINDFROMLOC function, if the from loc information is unknown.
        x = move->from_loc.row;
        y = &move->from_loc.col;
        
        if(y == 'a')
            transfy = 0;
        else if(y == 'b')
            transfy = 1;
        else if(y == 'c')
            transfy = 2;
        else if(y == 'd')
            transfy = 3;
        else if(y == 'e')
            transfy = 4;
        else if(y == 'f')
            transfy = 5;
        else if(y == 'g')
            transfy = 6;
        else if(y == 'h')
            transfy = 7;
        
        if(x == 8)
            transfx = 0;
        else if(x == 7)
            transfx = 1;
        else if(x == 6)
            transfx = 2;
        else if(x == 5)
            transfx = 3;
        else if(x == 4)
            transfx = 4;
        else if(x == 3)
            transfx = 5;
        else if(x == 2)
            transfx = 6;
        else if(x == 1)
            transfx = 7;
        
        board[transfx][transfy] = ' ';                                  // puts a blank space in the space after the piece has been moved.
        
        toy = &move->to_loc.col;
        tox = move->to_loc.row;
        
        if(toy == 'a')                                                  // Starts to translate the to loc information to array coordinates.
            transty = 0;
        else if(toy == 'b')
            transty = 1;
        else if(toy == 'c')
            transty = 2;
        else if(toy == 'd')
            transty = 3;
        else if(toy == 'e')
            transty = 4;
        else if(toy == 'f')
            transty = 5;
        else if(toy == 'g')
            transty = 6;
        else if(toy == 'h')
            transty = 7;
        
        if(tox == 8)
            transtx = 0;
        else if(tox == 7)
            transtx = 1;
        else if(tox == 6)
            transtx = 2;
        else if(tox == 5)
            transtx = 3;
        else if(tox == 4)
            transtx = 4;
        else if(tox == 3)
            transtx = 5;
        else if(tox == 2)
            transtx = 6;
        else if(tox == 1)
            transtx = 7;
        
        pieceinfo = &move->piece;                                        // Sets the piece in the to location. This sucessfully completes the move.
        
        if(move->color == 1)
            pieceinfo = tolower(pieceinfo);                             // sets the piece letter to uppercase or lowercase based on piece color.
        
        board[transtx][transty] = pieceinfo;
    }
    else
    {
        x = move->from_loc.row;
        y = move->from_loc.col;
        
        if(y == 'a')
            transfy = 0;
        else if(y == 'b')
            transfy = 1;
        else if(y == 'c')
            transfy = 2;
        else if(y == 'd')
            transfy = 3;
        else if(y == 'e')
            transfy = 4;
        else if(y == 'f')
            transfy = 5;
        else if(y == 'g')
            transfy = 6;
        else if(y == 'h')
            transfy = 7;
        
        if(x == 8)
            transfx = 0;
        else if(x == 7)
            transfx = 1;
        else if(x == 6)
            transfx = 2;
        else if(x == 5)
            transfx = 3;
        else if(x == 4)
            transfx = 4;
        else if(x == 3)
            transfx = 5;
        else if(x == 2)
            transfx = 6;
        else if(x == 1)
            transfx = 7;
        
        board[transfx][transfy] = ' ';
        
        toy = &move->to_loc.col;
        tox = move->to_loc.row;
        
        if(toy == 'a')
            transty = 0;
        else if(toy == 'b')
            transty = 1;
        else if(toy == 'c')
            transty = 2;
        else if(toy == 'd')
            transty = 3;
        else if(toy == 'e')
            transty = 4;
        else if(toy == 'f')
            transty = 5;
        else if(toy == 'g')
            transty = 6;
        else if(toy == 'h')
            transty = 7;
        
        if(tox == 8)
            transtx = 0;
        else if(tox == 7)
            transtx = 1;
        else if(tox == 6)
            transtx = 2;
        else if(tox == 5)
            transtx = 3;
        else if(tox == 4)
            transtx = 4;
        else if(tox == 3)
            transtx = 5;
        else if(tox == 2)
            transtx = 6;
        else if(tox == 1)
            transtx = 7;
        
        pieceinfo = &move->piece;
        
        if(move->color == 1)
            pieceinfo = tolower(pieceinfo);
        
        board[transtx][transty] = *pieceinfo;
    }
    
    
    
    
    
    
}

void findFromLoc(char **board, Move *move)
{
    
}
/*{                                                                       //I could not finish the find fromLoc function in time.
    int x;                                                                // But i still included what i worked on. and left eh function empty as to not cause any errors.
    int *y;
    int transty;
    int transtx;
    int i, j;
    int transfx;
    int transfy;
    
    
    
    x = move->to_loc.row;
    y = move->to_loc.col;                                               // But my idea was to translate the to location information to Array coordinates.
                                                                        // Then using the known information about each piece back track to all the possible places that a piece
    if(y == 'a')                                                        // might have come from. For example if a pawn was at h3 then we know that the only possible place for that
        transty = 0;                                                    //  pawn to come from is h2, Since the pawn can only move 1 row at a time except the first turn.
    else if(y == 'b')
        transty = 1;
    else if(y == 'c')
        transty = 2;
    else if(y == 'd')
        transty = 3;
    else if(y == 'e')
        transty = 4;
    else if(y == 'f')
        transty = 5;
    else if(y == 'g')
        transty = 6;
    else if(y == 'h')
        transty = 7;
    
    if(x == 8)
        transtx = 0;
    else if(x == 7)
        transtx = 1;
    else if(x == 6)
        transtx = 2;
    else if(x == 5)
        transtx = 3;
    else if(x == 4)
        transtx = 4;
    else if(x == 3)
        transtx = 5;
    else if(x == 2)
        transtx = 6;
    else if(x == 1)
        transtx = 7;
    
                                                                        //white move add numbers ---- this is because to go back to previous moves you have to add numbers to make a
    if(move->color == 1)                                                // piece go down the board, since whites start at the bottom of the board.
    {
        if(move->piece == 'P')
        {
            move->from_loc.row = ((move->to_loc.row) + 1);
        }
        else if(move->piece == 'R')
        {
            //move->from_loc.row = ((move->to_loc.row) );               // Each if else statement was ment for a different piece, since each piece has different moving styles.
        }
        else if(move->piece == 'N')
        {
            for ( i = 0; i < 8; i++)
            {
                for (j = 0; j < 8; j++)
                {
                    if (board[i][j] == 'n')
                    {
                        transfx = i;
                        transfy = j;
                        
                    }
                }
            }
        }
        else if(move->piece == 'B')
        {
            
        }
        else if(move->piece == 'Q')
        {
            
        }
        else if(move->piece == 'K')
        {
            
        }
    }                                                                   //Black Move subtract numbers --- since black pieces start at the top of the board and also the top of array,
                                                                        // You have to subtract numbers to go back to find the previous location.
    else if(move->color == 0)                                           // a starting point of a black piece you have to subtract numbers to backtrack to the starting position.
    {
        if(move->piece == 'P')
        {
            move->from_loc.row = ((move->to_loc.row) - 1);
        }
        else if(move->piece == 'R')
        {
            
            
        }
        else if(move->piece == 'N')
        {
            
        }
        else if(move->piece == 'B')
        {
            
        }
        else if(move->piece == 'Q')
        {
            
        }
        else if(move->piece == 'K')
        {
            
        }
    }
}
*/
double difficultyRating(void)                                           // It was pretty hard, could have finished the fromLoc function if i had just a little bit more time.
{
    double x = 4.0;
    return x;
}

double hoursSpent(void)                                                 // Should actually be countless, but thats not a double... ;)
{
    return 35;
                                                                        //Thanks for taking the time to read through the comments.
}                                                                       //Sincerely Tierd,
                                                                        //Subhash Naidu
