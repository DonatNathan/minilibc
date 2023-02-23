##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## It's my Makefile
##

src = src/strlen.asm	\
	  src/strchr.asm	\
	  src/strncmp.asm	\
	  src/strrchr.asm	\
	  src/memcpy.asm	\
	  src/memmove.asm	\
	  src/memset.asm	\
	  src/strcasecmp.asm	\
	  src/strcmp.asm	\
	  src/strcspn.asm	\
	  src/strpbrk.asm	\
	  src/strstr.asm	\
	  src/ffs.asm	\
	  src/syscall.asm	\
	  src/strfry.asm	\
	  src/memfrob.asm	\
	  src/index.asm	\
	  src/rindex.asm	\

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
	@rm -rf unit_tests
	@echo 'Executable deleted'

re : fclean all

run :
	@gcc main.c -o run -Wall -Werror
	LD_PRELOAD=./libasm.so ./run

tests_run: re
	gcc tests/*.c -W -Iinclude -o unit_tests --coverage -lcriterion -L/libasm.so
	./unit_tests

test: re
	mr_clean
	gcc tests/*.c -W -Iinclude -o unit_tests --coverage -lcriterion -L/libasm.so
	./unit_tests

.PHONY: re fclean clean all
