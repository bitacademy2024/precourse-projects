CC = gcc
CFLAGS = -Wall -O2
INCLUDES = -I /usr/local/eluon/mariadb/include/mysql
LDFLAGS = -L /usr/local/eluon/mariadb/lib -lmysqlclient
TARGET_DIR = target
TARGETS = $(TARGET_DIR)/test_conn $(TARGET_DIR)/test_insert $(TARGET_DIR)/test_delete

all: $(TARGETS)

$(TARGETS): %: %.o
	$(CC) -o $@ $^ $(LDFLAGS)

$(TARGET_DIR)/%.o: %.c
	@ mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $^

clean:
	rm -rf $(TARGET_DIR)