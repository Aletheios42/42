NAME = philo


C_FLAGS = -Werror -Wextra -Wall -Pthreads -g3

SRC_FILES = main.c\
					utils.c\
					philo.c\
SOURCES = (addpat Src/ SRC_FILES)

LIB = Lib/philo.h

all: NAME
	gcc $(C_FLAGS) $(LIB) $(SOURCES) -o $(NAME)

