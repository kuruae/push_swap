######### COLORS ########

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

######### FLAGS ########

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_PATH = libft

######### DIRECTORIES ########

SRC_DIR = src
OBJ_DIR = objs
INCLUDE_DIR = includes
# Add all include directories here
INCLUDE_DIRS = -I$(INCLUDE_DIR) -I$(LIBFT_PATH)/includes

######### FILES ########

SRC_FILES = $(SRC_DIR)/push_swap.c \
            $(SRC_DIR)/list_utils.c \
            $(SRC_DIR)/sort.c \
            $(SRC_DIR)/push.c \
            $(SRC_DIR)/swap_rotate.c \
            $(SRC_DIR)/sort_3_to_5.c \
            $(SRC_DIR)/parsing1.c \
            $(SRC_DIR)/parsing2.c

OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

######### LIBRARIES ########

LIBFT = $(LIBFT_PATH)/libft.a

######### NAME ########

NAME = push_swap

######### COMMANDS ########

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT)
	@echo "$(GREEN)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) -lft 2>/dev/null
	@echo "$(GREEN)✓ $(NAME) successfully compiled!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR) 2>/dev/null
	@$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c -o $@ $< 2>/dev/null
	@printf "$(GREEN)█$(RESET)"

$(LIBFT):
	@echo "$(GREEN)Building libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_PATH) >/dev/null 2>&1
	@echo "$(GREEN)✓ libft successfully compiled!$(RESET)"

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@$(MAKE) -C $(LIBFT_PATH) clean >/dev/null 2>&1
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)✓ Object files cleaned!$(RESET)"

fclean: clean
	@echo "$(RED)Removing executable...$(RESET)"
	@$(MAKE) -C $(LIBFT_PATH) fclean >/dev/null 2>&1
	@rm -f $(NAME)
	@echo "$(RED)✓ Executable removed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re