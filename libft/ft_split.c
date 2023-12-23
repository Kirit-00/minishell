/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:45:54 by maltun            #+#    #+#             */
/*   Updated: 2022/12/27 13:04:23 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	wordcounter(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s == '\0')
			return (i);
		while (*s != c && *s)
			s++;
		i++;
	}
	return (i);
}

int	start_split(char **ret, char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (*s)
	{
		while (*s && *s != c)
		{
			len++;
			s++;
		}
		if ((*s == c || *s == 0) && len > 0)
			ret[i++] = ft_substr(s - len, 0, len);
		len = 0;
		if (*s != 0)
			s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;

	if (!s)
		return (0);
	ret = malloc(sizeof(char *) * (wordcounter(s, c) + 1));
	if (!ret)
		return (0);
	ret[start_split(ret, s, c)] = 0;
	return (ret);
}
