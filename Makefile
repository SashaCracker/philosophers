NAME = philo

ALL_C = main.c ft_atoi.c ft_current_time.c ft_free.c ft_pars.c ft_philo.c ft_philos_init.c ft_waiter.c

HEADER = philosophers.h

OBJ = $(patsubst %.c,%.o,$(ALL_C))

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c Makefile philosophers.h
	gcc $(FLAGS) -c $< -o $@

$(OBJ): $(HEADER)

all: $(NAME)

clean:
	rm -f $(OBJ) $(BON_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re