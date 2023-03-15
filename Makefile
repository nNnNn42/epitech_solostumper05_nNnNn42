##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

CFLAGS = -W -Wall -Wextra -Werror

CC = gcc

FILES = main.c\
	strlen.c

OBJ = $(FILES:.c=.o)

TARGET_BINARY = rostring

all: clean $(TARGET_BINARY)

$(TARGET_BINARY) : $(OBJ)
	$(CC) $(FILES) -o $(TARGET_BINARY)

clean:
	rm -rf $(OBJ)
	rm -rf *.gc*

fclean : clean
	rm -rf $(TARGET_BINARY)


re : fclean all
	rm -rf $(OBJ)
