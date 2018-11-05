TARGET = hw14
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
CC = $(GCC) $(CFLAGS)

SRCS = hw14.c main.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --log-file

TESTFLAGS = -DTEST_MAIN -DTEST_CREATENODE -DTEST_LINKEDLISTCREATE -DTEST_SPLIT -DTEST_MERGE -DTEST_SORT -DLINKEDLIST

$(TARGET): $(OBJS)
	$(CC) $(TESTFLAGS) $(OBJS) -o $(TARGET)

.c.o:
	$(GCC) $(CFLAGS) $(TESTFLAGS) -c $*.c

testmemory: $(TARGET)
	$(VALGRIND)=./valgrind.log ./$(TARGET) inputs/test1.txt

testall: test1 test2

test1: $(TARGET)
	./$(TARGET) inputs/test1.txt > output1.txt
	diff output1.txt expected/expected1.txt

test2: $(TARGET)
	./$(TARGET) inputs/test2.txt > output2.txt
	diff output2.txt expected/expected2.txt

clean:
	rm -f $(OBJS) $(TARGET) *.txt *.log
