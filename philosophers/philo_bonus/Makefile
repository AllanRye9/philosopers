NAME = philo_bonus
CC = cc
HEADER = 	src/philo_bonus.h
SRC = 		src/destroy_bonus.c \
			src/ft_philo_bonus.c \
			src/init_bonus.c \
			src/main_bonus.c \
			src/monitor_bonus.c \
			src/utils_bonus.c

FLAGS = -Wall -Wextra -Werror -pthread

OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

all: $(NAME) $(OBJS) $(HEADER)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

bonus: all

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re