/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:33:01 by maltun            #+#    #+#             */
/*   Updated: 2023/11/21 18:37:52 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_token_type(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
			return (1);
		if (str[i] == '>')
			return (2);
		if (str[i] == '>' && str[i + 1] && str[i + 1] == '>')
			return (3);
		if (str[i] == '<')
			return (4);
		if (str[i] == '<' && str[i + 1] && str[i + 1] == '<')
			return (5);
		i++;
	}
	return (0);
}

void	word_by_word(t_struct *list, t_lexer *lexer)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(list->cmd, ' ');
	lexer->prev = 0;
	while (split[i])
	{
		lexer->str = split[i];
		lexer->i = i;
		lexer->token = check_token_type(split[i]);
		lexer->next = ft_calloc(1, sizeof(t_lexer));
		lexer->next->prev = lexer;
		if (split[i + 1])
			lexer = lexer->next;
		else
			lexer = 0;
		i++;
	}
	free(split);
}
