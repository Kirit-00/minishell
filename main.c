/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:22:11 by maltun            #+#    #+#             */
/*   Updated: 2023/11/09 17:05:29 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_arg(char **av, int ac)
{
	if (ac != 1)
	{
		printf("minishell: %s: No such file or directory\n", av[1]);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_struct	*list;

	if (check_arg(av, ac))
		return (2);
	list = ft_calloc(1, sizeof(t_struct));
	(void)ac;
	(void)av;
	(void)env;
	while (1)
	{
		if (list->cmd)
			free(list->cmd);
		list->cmd = readline("\033[36mMinishell: \033[33m");
		if (list->cmd && ft_strlen(list->cmd) != 0)
			add_history(list->cmd);
	}
	return (0);
}