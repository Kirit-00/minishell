/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:14:17 by maltun            #+#    #+#             */
/*   Updated: 2023/11/29 17:14:29 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_control(t_struct *list)
{
	char	*str;
	int		i;

	i = 0;
	str = list->cmd;
	list->tek_tirnak = 0;
	list->cift_tirnak = 0;
	while (str[i])
	{
		if (str[i] == '"')
		{
			list->cift_tirnak++;
			i++;
			if (str[i] == '"')
				i--;
			while (str[i] && str[i] != '"')
			{
				i++;
				if (str[i] == '"')
					list->cift_tirnak++;
			}
		}
		if (str[i] == '\'')
		{
			list->tek_tirnak++;
			i++;
			while (str[i] && str[i] != '\'')
			{
				i++;
				if (str[i] == '\'')
					list->tek_tirnak++;
			}
		}
		i++;
	}
	if (list->cift_tirnak % 2 != 0)
		exit_error(list, "cift tırnak kapanmadı");
	if (list->tek_tirnak % 2 != 0)
		exit_error(list, "tek tırnak kapanmadı");
}