SRCS = srcs/*.c
NAME = calc
CC = gcc
RM = rm -f
CFLAGS = `pkg-config --cflags gtk+-3.0`
FLAGS = `pkg-config --libs gtk+-3.0`

${NAME}:
		${CC} ${CFLAGS} -o ${NAME} ${SRCS} ${FLAGS}

all:	${NAME}
		./calc

clean:
		${RM} ${NAME}

re:		clean all

.PHONY: all clean re
