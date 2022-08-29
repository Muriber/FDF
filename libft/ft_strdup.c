/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:28:03 by bjimenez          #+#    #+#             */
/*   Updated: 2022/04/29 09:20:16 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	char	*pt;
	char	*qt;

	pt = dest;
	qt = src;
	while (*qt != '\0')
	{
		*pt = *qt;
		pt++;
		qt++;
	}
	*pt = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char			*p;
	unsigned long	size;

	size = ft_strlen(s1);
	p = (char *)malloc(sizeof(char) * (size + 1));
	if (p == NULL)
		return (NULL);
	ft_strcpy(p, (char *)s1);
	return (p);
}
