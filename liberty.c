#include "liberty.h"
#include <stdlib.h>
#include <stdio.h>


GoGame * readBoard(const char * filename){
    //fill this function to read from the given file and create a GoGame structure
    //both the GoGame struct and its internal array should be created on the heap
    FILE * readFile;
    GoGame * goBoard;

    readFile = fopen(filename, "r");
    if (readFile == NULL)
    {
        return NULL;
    }

    do
    {
        goBoard = malloc(sizeof(GoGame));
    } while (goBoard == NULL);
    fscanf(readFile, "%d\n", &goBoard -> size);
    
    goBoard -> board = malloc(sizeof(char *) * goBoard -> size);
    // while (linesRead < goBoard -> size)
    for (int i = 0; i < goBoard -> size; i++)
    {
        goBoard -> board[i] = malloc(sizeof(char) * (goBoard -> size + 1));
        if (goBoard -> board[i] == NULL)
        {
            i--;
            continue;
        }
        fgets(goBoard -> board[i], goBoard -> size + 2, readFile);
        goBoard -> board[i][goBoard -> size] = '\0';
        // printf("%s\n", goBoard -> board[i]);
    }

    fclose(readFile);
    return goBoard;
}

int getLiberty(GoGame * game, int x, int y){
    //Fill in this function to take in a GoGame and find the liberty of the piece at intersection (x,y)
    //Assume (x,y) is always a valid intersection with a piece
    int liberty = 0;
    char color;
    char nextTile;
    int nextX;
    int nextY;
    
    color = game -> board[y][x];
    if (color == '*')
    {
        return liberty;
    }
    game -> board[y][x] = 'L'; // converts the character to lowercase so it isn't counted twice

    for (int i = -1; i < 2; i += 2)
    {
        nextX = x + i;
        if (nextX < 0 || nextX >= game -> size)
        {
            continue;
        }
        nextTile = game -> board[y][nextX];
        if (nextTile == color)
        {
            liberty += getLiberty(game, nextX, y);
        }
        if (nextTile == '*')
        {
            liberty++;
            game -> board[y][nextX] = 'x';
        }
    }
    for (int j = -1; j < 2; j += 2)
    {
        nextY = y + j;
        if (nextY < 0 || nextY >= game -> size)
        {
            continue;
        }
        nextTile = game -> board[nextY][x];
        if (nextTile == color)
        {
            liberty += getLiberty(game, x, nextY);
        }
        if (nextTile == '*')
        {
            liberty++;
            game -> board[nextY][x] = 'x';
        }
    }
    

    // game -> board[x][y] = color; // automatically converted back to normal
    return liberty;
}

void freeBoard(GoGame * game){
    //Fill this function to free your GoGame structure from the heap
    for (int i = 0; i < game -> size; i++)
    {
        free(game -> board[i]);
    }
    free(game -> board);
    free(game);
}