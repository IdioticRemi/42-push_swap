# Program name

NAME	= push_swap

# Libraries

LIBFT	= ./libft

# Sources

__SRCS	= main.c

SRCS	= $(addprefix srcs/, $(__SRCS))
OBJS	= $(SRCS:.c=.o)

# Commands

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra
INCLUDE	= -I./includes
LIBS	= -L$(LIBFT) -lft

# Rules

%.o: %.c includes/$(NAME).h
	$(CC) $(CFLAGS) $(INCLUDE) $(LIBS) -c $< -o $@

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME) 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all