/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:08:55 by maltun            #+#    #+#             */
/*   Updated: 2023/01/02 20:57:13 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ret;

	i = 0;
	if (!dst && !dstsize)
		return (0);
	while (dst[i] && i < dstsize)
		i++;
	ret = ft_strlcpy(dst + i, (char *)src, dstsize - i);
	return (ret + i);
}
