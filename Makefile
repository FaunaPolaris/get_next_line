NAME		=	get_next_line
SRC_FILES	=	get_next_line.c get_next_line_utils.c
SRC_OBJS	=	$(SRC_FILES:.c=.o)
HEADER_FILE	=	get_next_line.h
CC		=	gcc
CC_FLAGS	=	-Wall -Wextra -Werror
MAIN		=	./mains/main.c
CLEAN		=	rm -rf

all: $(NAME)

$(NAME): $(SRC_OBJS)
	$(CC) $(CC_FLAGS) -I . $(MAIN) -o $(NAME) $(SRC_OBJS)

GDB: $(SRC_OBJS)
	$(CC) -g3 $(CC_FLAGS) -I . $(MAIN) -o $(NAME) $(SRC_OBJS)

split: $(SRC_OBJS)
	$(CC) -g3 $(CC_FLAGS) -I . ./mains/main_split.c -o split $(SRC_OBJS)

$(SRC_OBJS): $(SRC_FILES)
	$(CC) $(CC_FLAGS) -c $(SRC_FILES)
clean: 
	$(CLEAN) $(SRC_OBJS)

fclean: clean
	$(CLEAN) $(NAME)

re: fclean all

.PHONY: all clean fclean re GDB split
