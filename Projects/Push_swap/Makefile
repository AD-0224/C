
NAME = push_swap
HEADER = push_swap.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror


SRC = atoi_for_int.c \
      errors.c \
      ft_putstr_fd.c \
      ft_split.c \
      normalize_stack.c \
      pa.c \
      parsings.c \
      pb.c \
      ra.c \
      rb.c \
      rr.c \
      rra.c \
      rrb.c \
      rrr.c \
      sa.c \
      sb.c \
      sort_five.c \
      sort_four.c \
      sort_main.c \
      sort_three.c \
      sort_two.c \
      sort_small.c \
      ss.c \
      

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
