CC = gcc
CFLAGS = -Wall -O2
OBJS = main.o helloworld.o
TARGET_DIR = target
TARGET = $(TARGET_DIR)/helloworld

$(TARGET): $(OBJS) | $(TARGET_DIR)
	$(CC) -o $@ $^

$(TARGET_DIR): 
	mkdir -p $@
	
main.o: main.c helloworld.h
	$(CC) $(CFLAGS) -c $^

helloworld.o: helloworld.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -rf $(OBJS) $(TARGET_DIR)