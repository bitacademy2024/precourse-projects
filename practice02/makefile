CC = gcc
CFLAGS = -Wall -O2
TARGET_DIR = target
TARGET = $(TARGET_DIR)/phonebook
OBJS = $(TARGET_DIR)/main.o $(TARGET_DIR)/phonebook.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

$(TARGET_DIR)/%.o: %.c
	@ mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(TARGET_DIR)