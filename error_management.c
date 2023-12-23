/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergun <iergun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 01:44:13 by maltun            #+#    #+#             */
/*   Updated: 2023/11/25 03:31:44 by iergun           ###   ########.fr       */
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
	(void)ac;
	(void)av;
	return (0);
}

void	exit_error(t_struct *list, char *message)
{
	printf("\033[31mError: %s\n", message);
	free(list->cmd);
	list->cmd = NULL;
}
