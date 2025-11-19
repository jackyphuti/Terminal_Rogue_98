CXX = g++
CXXFLAGS = -std=c++98 -Wall

SRC = src/main.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = rogue98

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
