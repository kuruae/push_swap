### COMPILE ####################################################################
CC = cc
CFLAGS = -Wall -Wextra -Werror -O1 -g -I $(INC_DIR)

### to test different compilators on my macbook ################################
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	CC = cc
endif

### LIBRARIES ##################################################################
LIBFT_DIR = ../../circle1/libft
LIBFT = $(LIBFT_DIR)/libft.a

### NAME #######################################################################
NAME = push_swap

### SRCS #######################################################################
SRC  = push_swap.c
SRC += list_utils.c
SRC += sort.c
SRC += operations.c

### INC DIRECTORIES ############################################################
INC_DIR =./includes/
OBJ_DIR = objs

### OBJ FILES ##################################################################
OBJS := $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))

### COMMANDS ######################################################################
RM   = rm -f

################################################################################

$(OBJ_DIR)/%.o: %.c
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