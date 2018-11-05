TARGET = hw15
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
CC = $(GCC) $(CFLAGS)

SRCS = hw15.c main.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --log-file

TESTFLAGS = -DTEST_MAIN -DTEST_CREATENODE -DTEST_LINKEDLISTCREATE -DTEST_REMOVED -DLINKEDLIST

$(TARGET): $(OBJS)
	$(CC) $(TESTFLAGS) $(OBJS) -o $(TARGET)

.c.o:
	$(GCC) $(CFLAGS) $(TESTFLAGS) -c $*.c

testmemory: $(TARGET)
	$(VALGRIND)=./valgrind.log ./$(TARGET) inputs/test1.txt

testall: test1 test2 test3 test4

test1: $(TARGET)
	./$(TARGET) inputs/test1.txt > output1.txt
	diff output1.txt expected/expected1.txt

test2: $(TARGET)
	./$(TARGET) inputs/test2.txt > output2.txt
	diff output2.txt expected/expected2.txt

test3: $(TARGET)
	./$(TARGET) inputs/test3.txt > output3.txt
	diff output3.txt expected/expected3.txt

test4: $(TARGET)
	./$(TARGET) inputs/test4.txt > output4.txt
	diff output4.txt expected/expected4.txt

clean:
	rm -f $(OBJS) $(TARGET) *.txt *.log
