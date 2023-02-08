##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## It's my Makefile
##

PP = g++
src = src/strlen.asm	\

NAME = libasm.so
OBJ = ${src:.asm=.o}

${NAME}:
	@nasm -f elf64 ${src}
	@ld -shared -o libasm.so src/*.o
	@echo 'Files compiled'

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
