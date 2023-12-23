# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 00:30:46 by maltun            #+#    #+#              #
#    Updated: 2023/11/09 14:42:44 by maltun           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
list =  ft_isalpha.c         \
        ft_isdigit.c        \
        ft_isalnum.c        \
        ft_isascii.c        \
        ft_isprint.c        \
        ft_memcpy.c         \
        ft_memset.c         \
        ft_memmove.c        \
        ft_tolower.c        \
        ft_toupper.c        \
        ft_strlen.c         \
        ft_bzero.c          \
        ft_strlcpy.c        \
        ft_strlcat.c        \
        ft_strchr.c         \
        ft_strrchr.c        \
        ft_strncmp.c        \
        ft_memchr.c         \
        ft_memcmp.c         \
        ft_atoi.c           \
        ft_strdup.c         \
        ft_substr.c         \
        ft_strjoin.c        \
        ft_strtrim.c        \
        ft_itoa.c           \
        ft_split.c          \
        ft_calloc.c         \
        ft_strmapi.c        \
        ft_striteri.c       \
        ft_putchar_fd.c     \
        ft_putstr_fd.c      \
        ft_putnbr_fd.c      \
        ft_putendl_fd.c     \
        ft_strnstr.c
bonuslist = ft_lstnew.c         \
            ft_lstadd_front.c   \
            ft_lstsize.c        \
            ft_lstlast.c        \
            ft_lstadd_back.c    \
            ft_lstdelone.c      \
            ft_lstclear.c       \
            ft_lstiter.c        \
	    ft_lstmap.c
OBJS = $(list:.c=.o)
RED=\033[31m
YELLOW=\033[33m
GREEN=\033[32m
CYAN=\033[36m
BLUE=\033[34m
MAGENTA=\033[35m
RESET=\033[0m

bonusobj = $(bonuslist:.c=.o)

all: $(NAME)
	@echo "$(GREEN)Libft $(CYAN)Compiled $(GREEN)✓$(RESET)";

.c.o:
	@$(CC) -c $(CFLAGS) $<

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS) $(bonusobj)
	@echo "$(YELLOW)Libft $(RED)Deleted x$(RESET)";

fclean: clean
	@rm -f $(NAME)

re:fclean $(NAME)

bonus:  $(bonusobj) $(OBJS)
	@ar -rcs $(NAME) $(bonusobj) $(OBJS)

.PHONY: clean fclean all re bonus
