# Makefile

TARGET = shuf
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

#declare test flags, for example: TESTFLAGS = -DTEST_MAIN -DTEST_SHUF -DTEST_INTER -DTEST_DIV
TESTFLAGS = -DTEST_MAIN -DTEST_SHUF -DTEST_INTER -DTEST_DIV

SRCS =  main.c utility.c shuffle.c

OBJS = $(SRCS:%.c=%.o)

VALGRIND = valgrind --tool=memcheck --verbose --log-file

$(TARGET): $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o $(TARGET)
	
.c.o: 
	$(GCC) $(TESTFLAGS) -c $*.c 

val: shuf
	$(VALGRIND)=./logfile ./shuf 11

testall: test1 test2 test3

test1: shuf
	./shuf 4 | sort > output1.txt
	diff output1.txt expected/expected1.txt
	
test2: shuf
	./shuf 8 | sort > output2.txt
	diff output2.txt expected/expected2.txt

test3: shuf
	./shuf 11 | sort > output3.txt
	diff output3.txt expected/expected3.txt

clean:
	rm -f $(OBJS) $(TARGET) logfile *.txt
