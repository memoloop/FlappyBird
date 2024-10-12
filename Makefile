TARGET=game.exe
GCC=g++
INCLUDE_DIR=-I./include
LIB_BIR=-L./lib
DLLS=-lmingw32 -lSDL2main -lSDL2 -lSDL2_image
SRCS=$(wildcard source/*.cpp source/*/*.cpp)
OBJS=$(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(GCC) -o $@ $^ $(DLLS)

%.o: %.cpp
	$(GCC) -c $< -o $@

clean:
	del /Q /S *.o
	@if exist $(TARGET) del /Q $(TARGET)