#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include "liberty.h"


int main(int argc, char ** argv){

    //if filename not provided
    if (argc < 4){
        printf("Usage: %s <input filename> <int stoneX> <int stoneY>", argv[0]);
        return EXIT_FAILURE;
    }


    const char * filename = argv[1]; 
    int stoneX = atoi(argv[2]);
    int stoneY = atoi(argv[3]);

    //use student's readboard file
    GoGame * game = readBoard(filename);

    if (game == NULL){
        printf("readBoard() returns NULL, exiting...\n");
        return EXIT_FAILURE;
    }

    //use student's getLiberty file to find liberty of stone or group at (x,y)
    int l = getLiberty(game, stoneX, stoneY);

    //print liberty
    printf("%d", l);

    //free using student's free method
    freeBoard(game);
 
    return 0;
}