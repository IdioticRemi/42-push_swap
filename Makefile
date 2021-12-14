# Program name
NAME	= push_swap

# Directories
LIBFT	= libft/

INC_DIR	= includes/
SRC_DIR	= srcs/
OBJ_DIR	= objs/

# Sources
__SRCS	= main.c checker.c parsing.c op0.c op1.c pututil.c

SRCS	= $(addprefix $(SRC_DIR), $(__SRCS))
OBJS	= $(addprefix $(OBJ_DIR), $(__SRCS:.c=.o))

# Compile
CC		= clang

CFLAGS	= -Wall -Werror -Wextra -g -fsanitize=address
INCLUDE	= -I $(INC_DIR) -I $(LIBFT)
LIBS	= -L $(LIBFT) -lft

# Rules
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)/$(NAME).h
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBS) -o $(NAME)

all: $(NAME) 

clean:
	make -C $(LIBFT) clean
	rm -f $(OBJS)

fclean:
	make -C $(LIBFT) fclean
	rm -f $(NAME) $(OBJS)

re: fclean $(NAME) 