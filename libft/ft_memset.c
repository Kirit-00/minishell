/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:04:56 by maltun            #+#    #+#             */
/*   Updated: 2023/01/07 00:54:49 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	void	*ret;

	ret = b;
	while (len-- > 0)
		*(unsigned char *)b++ = (unsigned char)c;
	return (ret);
}
