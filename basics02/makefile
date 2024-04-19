CC = gcc
CFLAGS = -Wall -O2
TARGET_DIR = target
TARGETS = $(TARGET_DIR)/ex01 $(TARGET_DIR)/ex02 $(TARGET_DIR)/ex03 $(TARGET_DIR)/ex04 $(TARGET_DIR)/ex05 $(TARGET_DIR)/ex06 $(TARGET_DIR)/ex07

all: $(TARGETS)

$(TARGETS): %: %.o
	$(CC) -o $@ $^

$(TARGET_DIR)/%.o: %.c
	@ mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(TARGET_DIR)