### COMPILE ####################################################################
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -I $(INC_DIR)

### So I can work on my macbook ######################################################
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	CC = gcc
endif

### LIBRARIES ###################################################################
LIBFT_DIR = ../../circle1/libft
LIBFT = $(LIBFT_DIR)/libft.a

### NAME #########################################################################
NAME = push_swap

### SRCS ###############################################################################
SRC  = push_swap.c
SRC += list_utils.c

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

noflags: clean
	$(CC) $(SRC) -L$(LIBFT_DIR) -lft -o $(NAME)

clean :
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean : clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

run : all
	./$(NAME)

re: fclean all


.PHONY : all clean fclean run re noflags