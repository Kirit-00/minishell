SRCS =	main.c

CC = @gcc
NAME = minishell
CFLAGS = -Wall -Wextra -Werror
RM = @rm -rf
RED=\033[31m
YELLOW=\033[33m
GREEN=\033[32m
CYAN=\033[36m
BLUE=\033[34m
MAGENTA=\033[35m
RESET=\033[0m

OBJS = $(SRCS:.c=.o)

READLINE = readline

all: title $(READLINE) $(NAME)


$(READLINE):
	curl -O https://ftp.gnu.org/gnu/readline/readline-8.2.tar.gz
	tar -xvf readline-8.2.tar.gz
	cd readline-8.2 && ./configure --prefix=${PWD}/readline
	cd readline-8.2 && make install

title:
	@clear
	@echo "$(YELLOW)███╗   ███╗██╗███╗   ██╗██╗    ███████╗██╗  ██╗███████╗██╗     ██╗     ";
	@echo "████╗ ████║██║████╗  ██║██║    ██╔════╝██║  ██║██╔════╝██║     ██║     ";
	@echo "██╔████╔██║██║██╔██╗ ██║██║    ███████╗███████║█████╗  ██║     ██║     ";
	@echo "██║╚██╔╝██║██║██║╚██╗██║██║    ╚════██║██╔══██║██╔══╝  ██║     ██║     ";
	@echo "██║ ╚═╝ ██║██║██║ ╚████║██║    ███████║██║  ██║███████╗███████╗███████╗";
	@echo "╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝    ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝";

$(NAME): $(OBJS)
	@make -C libft/
	$(CC) -o $(NAME) $(OBJS) libft/libft.a $(CFLAGS) -L${PWD}/readline/lib  -I${PWD}/readline/include/ -lreadline
	@echo "$(GREEN)Minishell $(CYAN)Compiled ✓$(RESET)";

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I${PWD}/readline/include/

fclean: clean
	$(RM) $(NAME)
	@rm -rf readline-8.2 readline-8.2.tar.gz

clean:
	$(RM) $(OBJS)
	@echo "$(YELLOW)Minishell $(RED)Deleted x$(RESET)";
	@make fclean -C libft/

re: fclean all

.PHONY: all fclean clean re