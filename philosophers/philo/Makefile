NAME = philo
CC = cc
FLAGS = -Wall -Wextra -Werror
INCLUDE = -I.
LTHREAD = -lpthread
SRC = 	src/philo.c \
		src/main.c \
		src/utils.c \
		src/timer.c \
		src/clear.c \
		src/init.c  \
		src/philo_init.c \
		src/philo_life.c
OBJ = $(SRC:.c=.o)
%.o : %.c
		$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@
$(NAME) : $(OBJ) 
		$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LTHREAD)
all : $(NAME)
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY: all clean fclean re
