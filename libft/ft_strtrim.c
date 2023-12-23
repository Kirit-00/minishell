/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:34:14 by maltun            #+#    #+#             */
/*   Updated: 2022/12/23 13:04:52 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isset(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *source, const char *set)
{
	char	*ret;
	char	*start;
	char	*end;
	int		i;

	i = 1;
	if (!source || !set)
		return (0);
	start = (char *)source;
	end = start + ft_strlen(source);
	while (*start && ft_isset(*start, set))
		start++;
	while (ft_isset(*(end - 1), set) && i++)
		end--;
	ret = ft_substr(start, 0, ft_strlen(start) + 1 - i);
	return (ret);
}
