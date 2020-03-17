OBJS = main.o Implementation.o
EXEC = main
CFLAGS = -g -Wall -Werror
CC = gcc

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

run: $(EXEC)
	./$(EXEC)

clean: 
	rm -f $(EXEC) $(OBJS)