#include "liberty.h"
#include <stdlib.h>
#include <stdio.h>


int dfs(GoGame *game, int x, int y, int **visited);

GoGame * readBoard(const char * filename){
    //fill this function to read from the given file and create a GoGame structure
    //both the GoGame struct and it's internal array should be created on the heap
    FILE *fptr;
    fptr = fopen(filename, "r");

    if (fptr == NULL)
    {
        return NULL;
    }

    GoGame *game_board = (GoGame *)malloc(sizeof(GoGame));
    if (game_board == NULL)
    {
        return NULL;
    }

    if (fscanf(fptr, "%d", &game_board->size) != 1)
    {
        return NULL;
    }

    game_board->board = (char **)malloc(sizeof(char *) * game_board->size);

    for (int i = 0; i < game_board->size; i++)
    {
        game_board->board[i] = (char *)malloc(sizeof(char) * game_board->size);
        for (int j = 0; j < game_board->size; j++)
        {
            char current = fgetc(fptr);
            if (current != EOF && current != '\n')
            {
                game_board->board[i][j] = current;
            }
            else if (current == '\n')
            {
                j--;
            }
        }
    }

    fclose(fptr);
    return game_board;
}


int getLiberty(GoGame * game, int x, int y){
    //Fill in this function to take in a GoGame and find the liberty of the piece at intersection (x,y)
    //Assume (x,y) is always a valid intersection with a piece 
    int **visited = (int **)malloc(sizeof(int *) * game->size);

    if (visited == NULL)
    {
        return 0;
    }

    for (int i = 0; i < game->size; i++)
    {
        visited[i] = (int *)calloc(game->size, sizeof(int));
    }

    int result = dfs(game, x, y, visited);

    for (int i = 0; i < game->size; i++)
    {
        free(visited[i]);
    }
    free(visited);

    return result;
}

void freeBoard(GoGame * game){
    //Fill this function to free your GoGame structure from the heap
    if (game->board != NULL)
    {
        for (int i = 0; i < game->size; i++)
        {
            if (game->board[i] != NULL)
            {
                free(game->board[i]);
            }
        }
        free(game->board);
    }
    
    free(game);
}

int dfs(GoGame *game, int x, int y, int **visited)
{
    if (x < 0 || x >= game->size || y < 0 || y >= game->size)
    {
        return 0;
    }

    visited[y][x] = 1;

    char current = game->board[y][x];
    int liberty = 0;
    int directions[] = {0, 1, 0, -1, 1, 0, -1, 0};

    for (int i = 0; i < 8; i += 2)
    {
        int nx = directions[i + 1] + x;
        int ny = directions[i] + y;

        if (nx < 0 || nx >= game->size || ny < 0 || ny >= game->size || visited[ny][nx])
        {
            continue;
        }

        // Empty spot
        if (game->board[ny][nx] == '*')
        {
            liberty += 1;
            visited[ny][nx] = 1;
        }
        else if (game->board[ny][nx] == current)
        {
            liberty += dfs(game, nx, ny, visited);
        }

    }

    return liberty;
}