/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:25:35 by maltun            #+#    #+#             */
/*   Updated: 2023/12/23 19:19:48 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*ft_create_env_node(char *key, char *value)
{
	t_env *new;

	new = malloc(sizeof(t_env));
	if (new)
	{
		new->key = ft_strdup(key);
		new->value = ft_strdup(value);
		new->next = NULL;
	}
	return (new);
}

void	ft_add_list(t_env **env1, t_env *new)
{
	t_env *list;

	if(!env1 || !new)
		return ;
	if(*env1)
	{
		list = *env1;
		while(list && list->next)
			list = list->next;
		list->next = new;
	}
	else
		*env1 = new;
}