#Output directories
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

#TARGET
TARGET := $(BIN_DIR)/psx-comBINe

#Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
#Objects derived from Sources
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

#Compiler
CC := g++

#Flags
CPPFLAGS := -Iinclude -MMD -MP
CFLAGS   := -Wall -DBOOST_NO_CXX11_SCOPED_ENUMS
LDFLAGS  := -L/usr/include/boost -lboost_filesystem -lboost_system
LDLIBS   := -lm 

.PHONY: all install clean

all: $(TARGET)

#Make binary
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

#Make objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@ 

#Create obj and bin directory if they don't exist
$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

install: $(TARGET)
	mv ./$(TARGET) /usr/local/bin
	
#Remove objects and binary
clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)

-include $(OBJ:.o=.d)
