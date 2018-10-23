TARGET = joe
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
CC = $(GCC) $(CFLAGS)

SRCS = hw12.c main.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --log-file

TESTFLAGS = -DLINKEDLIST -DTEST_MAIN -DTEST_CREATENODE -DTEST_LINKEDLISTCREATE -DTEST_JOSEPHUS

$(TARGET): $(OBJS)
	$(CC) $(TESTFLAGS) $(OBJS) -o $(TARGET)

.c.o:
	$(GCC) $(CFLAGS) $(TESTFLAGS) -c $*.c

testmemory: $(TARGET)
	$(VALGRIND)=./valgrind.log ./$(TARGET) 100 3 20

testall: test1 test2 test3 test4 test5 test6

test1: $(TARGET)
	./$(TARGET) 10 3 1 > output1.txt
	diff output1.txt expected/expected1.txt

test2: $(TARGET)
	./$(TARGET) 10 4 2 > output2.txt
	diff output2.txt expected/expected2.txt

test3: $(TARGET)
	./$(TARGET) 8 5 3 > output3.txt
	diff output3.txt expected/expected3.txt

test4: $(TARGET)
	./$(TARGET) 8 9 1 > output4.txt
	diff output4.txt expected/expected4.txt

test5: $(TARGET)
	./$(TARGET) 41 3 1 > output5.txt
	diff output5.txt expected/expected5.txt

test6: $(TARGET)
	./$(TARGET) 100 3 20 > output6.txt
	diff output6.txt expected/expected6.txt

clean:
	rm -f $(OBJS) $(TARGET) *.txt *.log
