TARGET = gray
GCC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
CC = $(GCC) $(CFLAGS)

SRCS = bmpfunc.c bmpimage.c hw10.c

OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --tool=memcheck --verbose --log-file

TESTFLAGS = -DTEST_MAINFUNC -DTEST_FUNCGIVEN -DTEST_IMGTOGRAY -DTEST_HEADERVALID -DTEST_BMPOPENFILE -DTEST_BMPWRITEFUNC -DTEST_BMPFREEFUNC

$(TARGET): $(OBJS)
	$(CC) $(TESTFLAGS) $(OBJS) -o $(TARGET)

.c.o:
	$(GCC) $(CFLAGS) $(TESTFLAGS) -c $*.c

testmemory: $(TARGET)
	$(VALGRIND)=./valgrind.log ./$(TARGET) 7 2

testall: test1 test2 test3 test4

test1: $(TARGET)
	./$(TARGET) exampleImages/CondProb.bmp output1.bmp
	xxd expectedImages/expectedCondProb.bmp > excondprob.bin
	xxd output1.bmp > output1.bin
	diff output1.bin excondprob.bin

test2: $(TARGET)
	./$(TARGET) exampleImages/RV.bmp output2.bmp
	xxd expectedImages/expectedRV.bmp > exrv.bin
	xxd output2.bmp > output2.bin
	diff output2.bin exrv.bin

test3: $(TARGET)
	./$(TARGET) exampleImages/RV2.bmp output3.bmp
	xxd expectedImages/expectedRV2.bmp > exrv2.bin
	xxd output3.bmp > output3.bin
	diff output3.bin exrv2.bin	

test4: $(TARGET)
	./$(TARGET) exampleImages/RV2Small.bmp output4.bmp
	xxd expectedImages/expectedRV2Small.bmp > exrv2small.bin
	xxd output4.bmp > output4.bin
	diff output4.bin exrv2small.bin

clean:
	rm -f $(OBJS) $(TARGET) *.bmp *.bin
