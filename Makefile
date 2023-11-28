NAME = philo
RM = rm -f
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC = main.c \
    launch_threads_and_join.c \
    monitoring.c \
    utils/destroy.c \
    utils/ft_atoi.c \
    utils/get_time.c \
    utils/init_args.c \
    utils/init_forks.c \
    utils/init_philos.c \
    utils/panic.c \
    utils/routine.c \
    utils/valid_args.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

dev: all clean

.PHONY: all clean fclean re dev
