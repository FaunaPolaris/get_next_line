NAME		=	get_next_line
SRC_FILES	=	get_next_line.c get_next_line_utils.c
HEADER_FILE	=	get_next_line.h
CC		=	gcc
CC_FLAGS	=	-Wall -Wextra -Werror
OBJS		=	$(SRC_FILES: .c=.o)
MAIN		=	./mains/main.c

all: $(NAME)

$(NAME):
