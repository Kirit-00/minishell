NAME = minishell
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra -lreadline

SRCS = main.c

FLAGS_DATARACE = -g -fsanitize=address

RED=\033[31m
YELLOW=\033[33m
GREEN=\033[32m
CYAN=\033[36m
BLUE=\033[34m
MAGENTA=\033[35m
RESET=\033[0m

all: title  $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@rm -rf *.dSYM

title:
	@clear
	@echo "Minishell $(CYAN)By maltun$(RESET)";
	@echo "";	

tittle:
	@clear
	@echo "$(GREEN)****** Cleaned ******$(RESET)"
data_race:
	@$(CC) $(FLAGS_DATARACE) $(SRCS) -o $(NAME)	

clean:
	@$(RM) $(NAME) *.dSYM

fclean: tittle clean
	@$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re