CC = gcc
CFLAGS = -Wall -O2
OBJS = main.o helloworld.o
TARGET = helloworld

helloworld: $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

main.o: main.c helloworld.h
	$(CC) $(CFLAGS) -c main.c

helloworld.o: helloworld.c
	$(CC) $(CFLAGS) -c helloworld.c

clean:
	rm -f $(OBJS) $(TARGET)