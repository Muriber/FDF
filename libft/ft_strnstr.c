/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:30:36 by bjimenez          #+#    #+#             */
/*   Updated: 2022/04/29 11:58:35 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char		*q;
	unsigned long	i;
	unsigned long	j;

	i = 0;
	q = haystack;
	if (*needle == '\0')
		return ((char *)q);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
			q = &haystack[i];
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{	
			if (needle[j + 1] == '\0')
				return ((char *)q);
			j++;
		}
		i++;
	}
	return (0);
}
