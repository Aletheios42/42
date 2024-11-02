NAME = philo

CC = gcc
C_FLAGS = -Werror -Wextra -Wall -g3
C_FLAGS = -fsanitize=address


SRC_FILES = main.c \

SOURCES = $(addprefix Src/, $(SRC_FILES))
OBJECTS = $(SOURCES:.c=.o)
INCLUDES = -IInc/

all: $(NAME)

$(NAME): $(SOURCES)
	$(CC) $(C_FLAGS) $(INCLUDES) $(SOURCES) -o $(NAME)

clean:
	rm -f $(NAME)

