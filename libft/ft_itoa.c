/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:12:18 by maltun            #+#    #+#             */
/*   Updated: 2022/12/27 12:55:39 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static	size_t	ft_nlen(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len++;
	else if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ret;
	size_t	size;
	size_t	i;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_nlen(n);
	ret = malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	ret[size] = '\0';
	if (n < 0)
	{
		ret[0] = '-';
		n *= -1;
		i = 1;
	}
	while (i < size--)
	{
		ret[size] = (n % 10) + '0';
		n /= 10;
	}
	return (ret);
}
