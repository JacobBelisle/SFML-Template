CC		= g++
CFLAGS	= -g
SFMLFLAGS = -I src/include/ -L src/lib/ -lsfml-graphics -lsfml-window -lsfml-system
SFMLPATH = src/lib/
TARGET	= Game
HIDE = #@

all: build link exec clean

build:
	$(HIDE)$(CC) $(CFLAGS) -c *.cpp $(SFMLFLAGS)

link:
	$(HIDE)$(CC) -o $(TARGET) *.o $(SFMLFLAGS)

exec:
	$(HIDE)export LD_LIBRARY_PATH=src/lib/ && ./$(TARGET)

debug: build link
	$(HIDE)gdb -quiet $(TARGET)

clean:
	$(HIDE)rm -f *.o $(TARGET) *~ && echo \
