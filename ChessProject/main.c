//Subhash Naidu su162541
//Sean S. COP 3502
//Assignment 1 - ChessMoves

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ChessMoves.h"

void failwhale(void)
{
    printf("fail whale :(\n");
    exit(0);
}

char **createChessBoard(void)
{
	int rows = 8;
	int columns = 8;
	int i,j;

	char **board = (char **) malloc(rows * sizeof(char *));

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

char **destroyChessBoard(char **board)
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
        {
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


    return board;
}

void checkPiece(char *tok, Move *x)
{
    int i = 0;
    while (i < strlen(tok))
    {
        if (tok[i] == 'R')
        {
            x->piece = 'R';
            break;
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

void checkFrom( char *tok, Move *x)
{
    x->from_loc.col = '\0';
    int i;
    //col
    
    x->from_loc.col = 'x';

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
    

    x->from_loc.row = -1;
    //row
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

void checkTo(char *tok, Move *x)
{
    //col
    int i;
    
    x->to_loc.col = 'x';
    
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
    
    
    x->to_loc.row = -1;
    //row
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
    char input_data[30];
    strcpy(input_data, str);
    char *token;
    int i = 0;

    //tokenize string
    token = strtok(input_data, " ");
    token = strtok((NULL)," ");
    whiteMove->color = 1;
    
    
    while (i < strlen(token))
    {
        if (token[i] == 'x')
            whiteMove->isCapture = 1;
        i++;
        
    }
    checkPiece(token, whiteMove);
    checkFrom(token, whiteMove);
    checkTo(token, whiteMove);
    
    token = strtok((NULL)," ");
    
    while (i < strlen(token))
    {
        if (token[i] == 'x')
            blackMove->isCapture = 1;
        i++;
    }
    
    checkPiece(token, blackMove);
    checkFrom(token, blackMove);
    checkTo(token, blackMove);

}


void movePiece(char **board, Move *move);

void findFromLoc(char **board, Move *move);

double difficultyRating(void);

double hoursSpent(void);

int main(void)
{
    Move move;
    char **board = createChessBoard();
    
    // With this test case, I'm checking whether your movePiece() function
    // correctly moves a piece based on a Move that I know has been properly
    // initialized. (This is to ensure that you don't initialize Move structs
    // incorrectly in your program and then write a movePiece() function that
    // only works with that incorrect struct initialization.)
    
    // This test case will also help ensure that your movePiece() function does
    // not output the board to the screen. If it does, this program will print
    // the board twice after each move (instead of just once), which is not the
    // expected result.
    
    move.to_loc.col = 'f';
    move.to_loc.row = 3;
    move.from_loc.col = 'x';
    move.from_loc.row = -1;
    move.piece = 'N';
    move.isCapture = 0;
    move.color = WHITE;
    
    movePiece(board, &move);
    
    // Technically, this would be a legal move given this particular board
    // configuration. We would never encounter this situation in a real game,
    // though, because White never moves twice in a row without Black making a
    // move.
    
    move.to_loc.col = 'e';
    move.to_loc.row = 4;
    move.from_loc.col = 'x';
    move.from_loc.row = -1;
    move.piece = 'P';
    move.isCapture = 0;
    move.color = WHITE;
    
    movePiece(board, &move);
    
    move.to_loc.col = 'b';
    move.to_loc.row = 5;
    move.from_loc.col = 'x';
    move.from_loc.row = -1;
    move.piece = 'B';
    move.isCapture = 0;
    move.color = WHITE;
    
    movePiece(board, &move);
    
    printTestCaseBoard(board);
    
    // This program has a nasty memory leak, but I don't want to call your
    // destroyBoard() function in case it's broken. I want this test case's
    // success to be based entirely on your movePiece() function, and no other
    // functions.
    
    return 0;
}
