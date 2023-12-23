/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:20:14 by maltun            #+#    #+#             */
/*   Updated: 2023/12/23 18:59:35 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// # include <curses.h>
// # include <term.h>
// # include <unistd.h>
# include <stdio.h>
// # include <sys/wait.h>
// # include <signal.h>
# include "readline/readline.h"
# include "readline/history.h"
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_env
{
	char *key; // = den önceki kısımı tutuyoruz
	char *value; // = den sonraki kısım;
	struct s_env *next;
} t_env;

typedef struct s_struct
{
	char	*cmd;
	int		tek_tirnak; // tek tırnagın baslangıc ve bitişini kontrol eden flag 
	int		cift_tirnak; // cift tırnagın baslangıc ve bitişini kontrol eden flag 
	int		no_token1; // tek tırnagın icindeki tokenleri karakter olarak kontrol edebilmek icin 
	int		no_token2; // cift tırnagın icindeki tokenleri karakter olarak kontrol edebilmek icin 
}	t_struct;

typedef enum s_tokens
{
	PIPE = 1,
	GREAT,
	GREAT_GREAT,
	LESS,
	LESS_LESS,
}	t_tokens;

typedef struct s_lexer
{
	char			*str;
	t_tokens		token;
	int				i;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}	t_lexer;

int		check_arg(char **av, int ac);
void	check_quote(t_struct *list);
void	cmd_control(t_struct *list);
void	word_by_word(t_struct *list, t_lexer *lexer);
void 	get_line(t_list *list, t_lexer *lexer);
void	exit_error(t_struct *list, char *message);
char 	**env_and_str1(char *env);
void 	ft_init_env(t_env **env1, char **env);
int 	carlen(char *str, char c);
int 	strlen1(char *str);
void	ft_add_list(t_env **env1, t_env *new);
t_env	*ft_create_env_node(char *name, char *string);


#endif