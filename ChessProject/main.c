//Subhash Naidu su162541
//Sean S. COP 3502
//Assignment 1 - ChessMoves

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ChessMoves.h"

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
    Move *white = NULL;
    Move *black = NULL;
    parseNotationString(g, white, black);


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
    char *input_data;
    input_data = malloc(sizeof(char)*strlen(str));
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

void movePiece(char **board, Move *move)
{
	char *y = NULL;
	char *toy = NULL;
	int x;
	int tox;
	int transfx;
	int transfy;

	int transtx;
	int transty;
	char *pieceinfo;



	if(move->from_loc.col == 'x' || move->from_loc.row == -1)
	{
		findFromLoc(board, move);
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

		toy = move->to_loc.col;
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

		pieceinfo = move->piece;

		if(move->color == 1)
			pieceinfo = tolower(pieceinfo);

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

		toy = move->to_loc.col;
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

		pieceinfo = move->piece;

		if(move->color == 1)
			pieceinfo = tolower(pieceinfo);

		board[transtx][transty] = pieceinfo;
	}






}

void findFromLoc(char **board, Move *move)
{
	int x;
	int *y;
	int transty;
	int transtx;

	x = move->to_loc.row;
	y = move->to_loc.col;

	if(y == 'a')
		transty = 0;
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

	//white move add numbers
	if(move->color == 1)
	{
		if(move->piece == 'P')
		{
			move->from_loc.row = ((move->to_loc.row) + 1);
		}
		else if(move->piece == 'R')
		{
			for(int i = transtx; i < 8; i++)
			{
				for(int i = transtx; i < 0; i--)
				{
					for(int j = transty; j < 8; j++)
					{
						for(int j = transty; j < 0; j--)
						{

						}
					}
				}
			}
			move->from_loc.row = ((move->to_loc.row) );
		}
		else if(move->piece == 'K')
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
	}//Black Move subtract numbers
	else if(move->color == 0)
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

double difficultyRating(void)
{
	double x = 4.0;
	return x;
}

double hoursSpent(void)
{
	return 30;

}
