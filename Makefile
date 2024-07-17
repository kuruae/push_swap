### COMPILE ####################################################################
CC = cc
CFLAGS = -Werror -Wextra -Wall -g3 -I $(INC_DIR)

### LIBRARIES ###################################################################
LIBFT_DIR = ../../circle1/libft
LIBFT = $(LIBFT_DIR)/libft.a

### NAME #########################################################################
NAME = push_swap.a

### SRCS ###############################################################################
SRC  = push_swap.c

### INC DIRECTORY #################################################################
INC_DIR =./includes/

### OBJ FILES #####################################################################
OBJS := $(SRC:.c=.o)

### COMMANDS ######################################################################
RM   = rm -f

################################################################################

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

clean :
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean : clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

run : all
	./$(NAME)

re: fclean all

.PHONY : all clean fclean run re
