/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:22:11 by maltun            #+#    #+#             */
/*   Updated: 2023/11/09 15:56:37 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	//char	*cmd;

	(void)ac;
	(void)av;
	(void)env;
	while (1)
	{
		if (*env)
			printf("%s\n", *env);
		else
			break;
		env++;
		//cmd = readline("\033[36mMinishell: \033[33m");
		//add_history(cmd);
		//free(cmd);
	}
	return (0);
}