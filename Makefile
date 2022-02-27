CC=gcc
TARGET=tic-tac-toe
LIB_C=lib/tic-tac-toe.c
LIB_TARGET=lib/tic-tac-toe.o
MAIN=tic-tac-toe.c

tic-tac-toe: $(MAIN) $(LIB_TARGET)
	$(CC) $(LIB_TARGET) $(MAIN) -o $(TARGET)
	chmod a-w help/help.txt

$(LIB_TARGET): $(LIB_C)
	$(CC) -c $(LIB_C) -o $(LIB_TARGET)

clean:
	rm -f $(LIB_TARGET) $(TARGET)

all: clean tic-tac-toes