NAME = printf

SRC_DIR = ./src/
INC_DIR = ./includes/
OBJ_DIR = ./obj/

OBJC = $(SRC_DIR:.c=OBJ_DIR.o)

FLAGS = -Werror -Wextra -Wall

all:
	gcc main.c src/*.c -I includes/printf.h libft/libft.a -o printf