CC = gcc
CFLAGS = -Wall -O2
INCLUDES = -I /usr/local/eluon/mariadb/include/mysql
LDFLAGS = -L /usr/local/eluon/mariadb/lib -lmysqlclient
TARGET_DIR = target
TARGET = $(TARGET_DIR)/phonebook
OBJS = $(TARGET_DIR)/main.o $(TARGET_DIR)/phonebook.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

$(TARGET_DIR)/%.o: %.c
	@ mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $^

clean:
	rm -rf $(TARGET_DIR)