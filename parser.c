/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:33:01 by maltun            #+#    #+#             */
/*   Updated: 2023/12/23 17:11:45 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tokens	check_token_type(char *str, t_struct *list)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"' && !list->no_token2)
			list->no_token1 = !list->no_token1;
		if (str[i] == '\'' && !list->no_token1)
			list->no_token2 = !list->no_token2;
		if (!list->no_token1 && !list->no_token2 && str[i] == '|')
			return (PIPE);
		if (!list->no_token1 && !list->no_token2 && str[i] == '>' \
		&& str[i + 1] && str[i + 1] == '>')
			return (GREAT_GREAT);
		if (!list->no_token1 && !list->no_token2 && str[i] == '<' \
		&& str[i + 1] && str[i + 1] == '<')
			return (LESS_LESS);
		if (!list->no_token1 && !list->no_token2 && str[i] == '>')
			return (GREAT);
		if (!list->no_token1 && !list->no_token2 && str[i] == '<')
			return (LESS);
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
		lexer->token = check_token_type(split[i], list);
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
