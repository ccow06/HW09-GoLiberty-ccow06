# Calculating Liberty in Go

## Why Go?

Go is one of the oldest board games in the world. Unlike chess, Go resisted artificial intelligence for much longer because of its vast number of possible board states and the difficulty of evaluating positions. 

The breakthrough came with AlphaGo, an AI developed by DeepMind, which combined deep learning and reinforcement learning to defeat some of the strongest professional players in the world. This was a landmark achievement because it showed that AI could move beyond brute-force search. Now, we live in a world of more creative solutions.

AlphaGo’s victory demonstrated the potential of machine learning to tackle complex, uncertain problems, influencing research far beyond games.

If you are interested in learning more about the story of AlphaGo, linked below is an amazing documentary:

[![Watch the video](https://resizing.flixster.com/5SegS0ix_WFF1tZ2TjMFy8J9s0Q=/fit-in/705x460/v2/https://resizing.flixster.com/-XZAfHZM39UwaGJIFWKAE8fS0ak=/v3/t/assets/p14087603_v_h10_aa.jpg)](https://www.youtube.com/watch?v=WXuK6gekU1Y&ab_channel=GoogleDeepMind)

## Learning Objectives

In this assignment you will:
- Read characters and integers from files
- Dynamically generate multi-dimentional arrays
- Use structures for clean code
- Pass data by address to other functions
- Practice good recursion behaviors




## Introduction to Liberty in Go

In Go, Liberties are the free intersections adjacent to a given stone or other stone's of same color in its group. Stones form groups when those of the same color are placed next to each other (see below). Association is by cardinal direction, so diagonals do not count. 

![Liberty in Go](https://upload.wikimedia.org/wikipedia/commons/9/92/Go_adjacent_stones.png)

The liberty of a stone is the same as any of the other stones in it's group. Thus, a stone's liberty is the sum of its own personal liberty and the unique liberties of other's in the group.

In the game of Go, when liberties are exhausted by the other color (I.E. becomes zero), the piece(s) can be captured. 
## Part 1:  Reading Board From a File

#### Function 1: Counting Character Frequencies

You need to implement the following function in liberty.c: 

```c
GoGame * readBoard(const char * filename);
```

In this function, the input filename is given. Input files have two parts:
- Line 1 containing the size N of the board (5 for a 5x5 board)
- N rows of characters N deep

In this progam, open intersections will be represented by the char ```*```, while black stones and white stones are ```B``` and ```W``` respectively.


Here is an example file representing a 6x6 board:
```txt
6
******
**WWW*
***BB*
****W*
******
******
```

We have given a handy struct to keep track of board and size in one place: 

```c
typedef struct GoGame {
    int size;
    char ** board;
} struct
```

Allocate and intialize this struct with the proper data, then return.






## Part 2: Calculating Liberty



As mentioned before, liberty is the sum of all liberties of a stone and its group. Using recursion, check the neighboring intersections of the start stone and move through its group summing up all liberties you come across.  

Make sure to ignore duplicates and other colored stones. 

You will implement the following function:

```c
int getLiberty(GoGame *, int x, int y);
```

X and Y are the coordinates of the start intersection. This will always be a stone. From there, return the liberties of that stone or that of the group it is a part of.


## Step 3: Freeing the board

Finally, we want to free the board state we stored in the heap. Make sure to free both the struct and any heap elements referenced within.

Implement the following function:

```c
void freeBoard(GoGame *);
```


## Step 4 : Submitting
Submit ```liberty.c``` to Gradescope