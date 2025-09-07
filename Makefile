# ***
# *** DO NOT modify this file 
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 

SRCS = main.c liberty.c
OBJS = $(SRCS:%.c=%.o)

hw09: $(OBJS) 
	$(GCC) $(OBJS) -o hw09

testall: test1 test2 test3

test1: hw09
	./hw09 inputs/test1 2 2 > output1
	diff output1 expected/expected1

test2: hw09
	./hw09 inputs/test2 3 4 > output2
	diff output2 expected/expected2

test3: hw09
	./hw09 inputs/test3 2 6 > output3
	diff output3 expected/expected3

clean:
	rm -f output?
	rm -f hw09 *.o

.c.o: 
	$(GCC) -c $*.c 



