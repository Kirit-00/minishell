/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:22:11 by maltun            #+#    #+#             */
/*   Updated: 2023/11/09 02:02:03 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*str;
	char	*str2;

	(void)ac;
	(void)av;
	(void)env;
	while (1)
	{
		printf("--------------------\n");
		str = readline("isim : ");
		str2 = readline("soyisim : ");
		printf("--------------------\n%s\n", str);
		printf("%s\n", str2);
		free(str);
	}
	return (0);
}