CC = gcc
FLAGS = -Wall -Wextra -Werror
LIB = libft/libft.a
SRC = first_colon.c ft_numlen.c main.c maj_min_len.c major.c minor.c \
	mode2str.c second_colon.c time2str.c parse_input.c get_source.c \
	put_error.c
OBJ = main.o first_colon.o second_colon.o ft_numlen.o maj_min_len.o \
	major.o minor.o mode2str.o time2str.o parse_input.o get_source.o \
	put_error.o
HDRS = include/ft_ls.h
NAME = ft_ls

all: $(NAME)

$(NAME): $(LIB) $(HDRS) $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -L. $(LIB)

$(LIB):
	cd libft && make clean && make

main.o: main.c
	$(CC) $(FLAGS) -c main.c
first_colon.o: first_colon.c
	$(CC) $(FLAGS) -c first_colon.c
ft_numlen.o: ft_numlen.c
	$(CC) $(FLAGS) -c ft_numlen.c
maj_min_len.o: maj_min_len.c
	$(CC) $(FLAGS) -c maj_min_len.c
major.o: major.c
	$(CC) $(FLAGS) -c major.c
minor.o: minor.c
	$(CC) $(FLAGS) -c minor.c
mode2str.o: mode2str.c
	$(CC) $(FLAGS) -c mode2str.c
second_colon.o: second_colon.c
	$(CC) $(FLAGS) -c second_colon.c
time2str.o: time2str.c
	$(CC) $(FLAGS) -c time2str.c
parse_input.o: parse_input.c
	$(CC) $(FLAGS) -c parse_input.c
get_source.o: get_source.c
	$(CC) $(FLAGS) -c get_source.c
put_error.o: put_error.c
	$(CC) $(FLAGS) -c put_error.c

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(NAME) $(LIB)

re:
	make fclean all

