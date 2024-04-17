CC = gcc
CFLAGS = -Wall -O2
OBJS = main.o helloworld.o
TARGET_DIR = target
TARGETS = $(TARGET_DIR)/prob01 $(TARGET_DIR)/prob02 $(TARGET_DIR)/prob03 $(TARGET_DIR)/prob04 $(TARGET_DIR)/prob05

all: $(TARGETS)

$(TARGETS): %: %.o
	$(CC) -o $@ $^

$(TARGET_DIR)/%.o: %.c
	@ mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(TARGET_DIR)