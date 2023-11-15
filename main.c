/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:22:11 by maltun            #+#    #+#             */
/*   Updated: 2023/11/15 15:53:21 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_cmd_line(t_struct *list)
{
	if (list->cmd)
		free(list->cmd);
	list->cmd = readline("\033[36mMinishell: \033[33m");
	check_quote(list);
	if (list->cmd && ft_strlen(list->cmd) != 0)
		add_history(list->cmd);
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
		get_cmd_line(list);
	}
	return (0);
}
