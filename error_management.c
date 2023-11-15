/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 01:44:13 by maltun            #+#    #+#             */
/*   Updated: 2023/11/15 15:53:03 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_arg(char **av, int ac)
{
	if (ac != 1)
	{
		printf("\033[31mminishell: %s: No such file or directory\n", av[1]);
		return (1);
	}
	return (0);
}

void	exit_error(t_struct *list, char *message)
{
	printf("\033[31mError: %s\n", message);
	free(list->cmd);
	free(list);
	exit(2);
}

void	check_quote(t_struct *list)
{
	int	i;
	int	quote;
	int	quote2;

	i = 0;
	quote = 0;
	quote2 = 0;
	while (list->cmd[i])
	{
		if (list->cmd[i] == '\'' && (!i || \
		(list->cmd[i - 1] && list->cmd[i - 1] != '\\')))
			quote++;
		if (list->cmd[i] == '\"' && (!i || \
		(list->cmd[i - 1] && list->cmd[i - 1] != '\\')))
			quote2++;
		i++;
	}
	if (quote % 2 || quote2 % 2)
		exit_error(list, "you have to close \" or \'");
}
