#include "liberty.h"
#include <stdlib.h>
#include <stdio.h>


GoGame * readBoard(const char * filename){
    //fill this function to read from the given file and create a GoGame structure
    //both the GoGame struct and it's internal array should be created on the heap
    return NULL;
}


int getLiberty(GoGame * game, int x, int y){
    //Fill in this function to take in a GoGame and find the liberty of the piece at intersection (x,y)
    //Assume (x,y) is always a valid intersection with a piece 
    return 0;
}

void freeBoard(GoGame * game){
    //Fill this function to free your GoGame structure from the heap
}