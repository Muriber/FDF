/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:01:52 by bjimenez          #+#    #+#             */
/*   Updated: 2022/04/28 11:22:39 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long			i;
	unsigned char			*p;
	unsigned char			*q;

	p = dst;
	q = (unsigned char *)src;
	i = 0;
	if (dst < src)
	{	
		while (i < len)
		{
			p[i] = q[i];
			i++;
		}
	}
	else if (dst > src)
	{
		while (len > 0)
		{
			p[len - 1] = q[len - 1];
			len--;
		}
	}
	return (dst);
}
