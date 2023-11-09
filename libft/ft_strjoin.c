/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:12:02 by maltun            #+#    #+#             */
/*   Updated: 2022/12/19 09:50:14 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*ret;
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (0);
	ret = result;
	while (s1[i])
	{
		*result = s1[i++];
		result++;
	}
	i = 0;
	while (s2[i])
	{
		*result = s2[i++];
		result++;
	}
	*result = '\0';
	return (ret);
}
