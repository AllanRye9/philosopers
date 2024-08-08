NAME = philo_bonus
CC = cc
FLAGS = -Wall -Wextra -Werror -g3
INCLUDE = -I.
LTHREAD = -lpthread
SRC = 	src/philo.c \
		src/main.c \
		src/utils.c \
		src/timer.c \
		src/clear.c \
		src/init.c  \
		src/philo_init.c
OBJ = $(SRC:.c=.o)
%.o : %.c
		$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@
$(NAME) : $(OBJ) 
		$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LTHREAD)
all : $(NAME)
bonus : all
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY: all clean fclean re
