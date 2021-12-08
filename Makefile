NAME	= calc
CC		= gcc
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror `pkg-config --cflags gtk+-3.0`
FLAGS	= `pkg-config --libs gtk+-3.0`
OBJ		= objs
OBJS	= $(addprefix $(OBJ)/, $(SRCS:.c=.o))
SRCS	=	main.c \
			international.c \
			international_process.c \
			national.c \
			national_process.c \
			read_file.c

$(NAME): $(OBJ) $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(FLAGS)

$(OBJ):
	@mkdir -p $(OBJ)

$(OBJ)/%.o: ./%.c
	$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

clean:
		$(RM) $(NAME)

fclean:	clean
	$(RM) $(OBJ)

re:		fclean all

.PHONY: all clean fclean re
