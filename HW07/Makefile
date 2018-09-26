WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFLAGS = -DTEST_MERGE -DTEST_MERGESSORT -DTEST_MERGESORT

SRCS = main.c
OBJS = $(SRCS:%.c=%.o)

hw07: $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o hw07

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c

testmemory: hw07
	$(VAL) ./hw07 Input/Test1 output1

testall: test1 test2 test3

test1: hw07
	./hw07 Input/Test1 output1
	diff output1 Expected/Expected1

test2: hw07
	./hw07 Input/Test2 output2
	diff output2 Expected/Expected2

test3: hw07
	./hw07 Input/Test3 output3 
	diff output3 Expected/Expected3

testRand: hw07
	shuf -r -i 1-1000 -n 10000 > Input/Test
	sort -n Input/Test > Expected/Expected
	./hw07 Input/Test output
	diff output Expected/Expected

clean: 
	rm -f hw07 *.o output? memcheck.txt
