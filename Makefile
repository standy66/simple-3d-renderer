CC := g++
CC_FLAGS := -std=c++11
LD := g++
LD_FLAGS := 

SOURCE_DIR	:= src
TARGET_DIR	:= output
TARGET_NAME	:= renderer
TARGET := $(TARGET_DIR)/$(TARGET_NAME)

SOURCE_FILES	:= $(wildcard $(SOURCE_DIR)/*.cpp)
HEADER_FILES	:= $(wildcard $(SOURCE_DIR)/*.h)
OBJECT_FILES	:= $(patsubst $(SOURCE_DIR)%.cpp,$(TARGET_DIR)%.o,$(SOURCE_FILES))

all: $(TARGET)

$(TARGET): $(OBJECT_FILES)
	$(LD) $(LD_FLAGS) $(OBJECT_FILES) -o $(TARGET)

$(TARGET_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

clean:
	rm $(TARGET) $(OBJECT_FILES)
