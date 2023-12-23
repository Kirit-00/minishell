/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:56:51 by maltun            #+#    #+#             */
/*   Updated: 2022/12/19 09:45:59 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*ret;

	if (!dst && !src)
		return (0);
	ret = dst;
	while (n-- > 0)
		*(char *)dst++ = *(char *)src++;
	return (ret);
}
