/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:22:11 by maltun            #+#    #+#             */
/*   Updated: 2023/12/23 19:21:36 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_cmd_line(t_struct *list)
{
	if (list->cmd)
		free(list->cmd);
	printf("\033[36m");
	list->cmd = readline("Minishell: ");
	printf("\033[35m");
	if (list->cmd && ft_strlen(list->cmd) != 0)
		add_history(list->cmd);
}

char	*debug_token(t_tokens token)
{
	if (token == GREAT)
		return "great";
	else if (token == GREAT_GREAT)
		return "greater";
	else if (token == LESS)
		return "less";
	else if (token == LESS_LESS)
		return "lesser";
	else if (token == PIPE)
		return "pipe";
	else
		return ("null");
}

int	main(int ac, char **av, char **env)
{
	t_struct	*list;
	t_lexer		*lexer;
	t_env		*env1;

	if (check_arg(av, ac))
		return (2);
	list = ft_calloc(1, sizeof(t_struct));
	lexer = ft_calloc(1, sizeof(t_lexer));
	ft_init_env(&env1, env);
	printf("\033[H\033[J");
	while (1)
	{
		get_cmd_line(list);
		cmd_control(list);
		if (list->cmd)
		{
			word_by_word(list, lexer);
			while (lexer->next)
			{
				printf("(word: %s) (token: %s) (index :%d)\n",\
				lexer->str, debug_token(lexer->token), lexer->i);
				lexer = lexer->next;
				free(lexer->prev->str);
				free(lexer->prev);
			}
			// while (env1->next)
			// {
			// 	printf("%s=%s\n", env1->key, env1->value);
			// 	env1 = env1->next;
			// }
		}
	}
	return (0);
}
