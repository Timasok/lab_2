TARGET = lab
CC 	   = gcc

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

$(TARGET) : $(OBJ)
	@$(CC) $(OBJ) -lm -o $(TARGET)

%.o : %.c
	@$(CC) -c $< -lm -o $@

clean:
	@rm $(TARGET) *.o