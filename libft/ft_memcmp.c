/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:39:12 by bjimenez          #+#    #+#             */
/*   Updated: 2022/04/29 13:26:44 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*p;
	const unsigned char	*q;

	p = (const unsigned char *)s1;
	q = (const unsigned char *)s2;
	i = 0;
	if (n == 0 || s1 == s2)
		return (0);
	else
	{
		while (i < n)
		{
			if (p[i] != q[i])
				return (p[i] - q[i]);
			i++;
		}
		return (0);
	}
}
