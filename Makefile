# Program name
NAME	= push_swap

# Directories
LIBFT	= libft/

INC_DIR	= includes/
SRC_DIR	= srcs/
OBJ_DIR	= objs/

# Sources
__SRCS	= main.c parsing.c ops.c lstutil.c sort.c

SRCS	= $(addprefix $(SRC_DIR), $(__SRCS))
OBJS	= $(addprefix $(OBJ_DIR), $(__SRCS:.c=.o))

# Compile
CC		= gcc

CFLAGS	= -Wall -Werror -Wextra -O3
INCLUDE	= -I $(INC_DIR) -I $(LIBFT)
LIBS	= -L $(LIBFT) -lft

# Color

FG_MAGE	= \033[0;35m
FG_CYAN	= \033[0;36m
FG_WHIT	= \033[0;37m
FG_GREE	= \033[0;32m

# Rules
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)/$(NAME).h
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@printf "."

$(NAME): $(OBJS)
	@printf " [$(words $(OBJS))]\n"
	@make -s -C $(LIBFT) all
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBS) -o $(NAME)
	@printf "[ PUSH-SWAP ] $(FG_GREE)Built '$(NAME)'.$(FG_WHIT)\n"

all: log $(NAME)

log:
	@printf "[ PUSH-SWAP ] $(FG_CYAN)Starting build process.$(FG_WHIT)\n"

clean:
	@make -s -C$(LIBFT) clean
	@rm -f $(OBJS)
	@printf "[ PUSH-SWAP ] $(FG_MAGE)Build objects cleaned.$(FG_WHIT)\n"

fclean:
	@make -s -C $(LIBFT) fclean
	@rm -f $(NAME) $(OBJS)
	@printf "[ PUSH-SWAP ] $(FG_MAGE)Program files cleaned.$(FG_WHIT)\n"

norm:
	@norminette $(SRC_DIR)

re: fclean all