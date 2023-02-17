##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## It's my Makefile
##

src = src/strlen.asm	\
	  src/strchr.asm	\
	  src/strncmp.asm	\
	  src/memcpy.asm	\
	  src/memmove.asm	\
	  src/memset.asm	\
	  src/strcasecmp.asm	\
	  src/strcmp.asm	\
	  src/strcspn.asm	\
	  src/strpbrk.asm	\
	  src/strrchr.asm	\
	  src/strstr.asm	\

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
	@gcc main.c -o run -Wall -Werror
	LD_PRELOAD=./libasm.so ./run

.PHONY: re fclean clean all
