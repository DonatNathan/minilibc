##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## It's my Makefile
##

src = src/strlen.asm	\
	  src/strchr.asm	\

NAME = libasm.so
OBJ = ${src:.asm=.o}

${NAME}: ${OBJ}
	@ld -shared -o libasm.so ${OBJ}
	@echo 'Files compiled'

%.o: %.asm
	@nasm -f elf64 -o $@ $<

all : ${NAME}

clean :
	@rm -rf ${OBJ}
	@echo 'Temporary files deleted'
fclean : clean
	@rm -rf ${NAME}
	@rm -rf run
	@echo 'Executable deleted'

re : fclean all

run :
	gcc main.c -o run
	LD_PRELOAD=./libasm.so ./run

.PHONY: re fclean clean all
