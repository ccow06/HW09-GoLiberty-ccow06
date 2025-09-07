#ifndef LIBERTY
#define LIBERTY


typedef struct GoGame {
    int size;
    char ** board;
} GoGame;

GoGame * readBoard(char const *);
int getLiberty(GoGame*, int, int);
void freeBoard(GoGame*);

#endif