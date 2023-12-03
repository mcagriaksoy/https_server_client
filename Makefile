# Mehmet Cagri Aksou - 2023

CC = g++
CPP_FLAGS = -O0 -std=c++11 -Wall -I /usr/local/include/gtest/
LIBS = -lssl -lcrypto

SRC_DIR = $(CURDIR)/src
TEST_DIR = $(CURDIR)/test
BUILD_DIR = $(CURDIR)/build
GTEST_DIR = /usr/local/lib/libgtest.a

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)

OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))
OBJ_FILES += $(patsubst $(TEST_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(TEST_FILES))

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo ">> Compiling $<"
	$(CC) $(CPP_FLAGS) -c -o $@ $< $(LIBS)

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	@echo ">> Compiling $<"
	$(CC) $(CPP_FLAGS) -c -o $@ $< $(LIBS)

.PHONY : all
all: http_server_client

http_server_client: $(OBJ_FILES)
	@echo ">> Linking $@..."
	$(CC) $(CPP_FLAGS) -o $@ $(OBJ_FILES) $(GTEST_DIR) $(LIBS)
	@echo "-------------------------"
	@echo "BUILD COMPLETE: $@"
	@echo "-------------------------"

.PHONY: clean
clean:
	@-rm -rf $(BUILD_DIR) http_server_client
	@echo "--------------"
	@echo "CLEAN COMPLETE"
	@echo "--------------"
