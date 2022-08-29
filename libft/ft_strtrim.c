/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:10:41 by bjimenez          #+#    #+#             */
/*   Updated: 2022/05/04 12:10:24 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_gp(unsigned long j, unsigned long len, char const *st1, char *t)
{
	char	*q;
	int		i;

	i = 0;
	q = t;
	while (st1[j + i] != '\0' && (j + i) < len)
	{
		q[i] = st1[j + i];
		i++;
	}
	q[i] = '\0';
	return (q);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*p;
	unsigned long	j;
	unsigned long	i;
	unsigned long	len;

	j = 0;
	i = 0;
	if (!s1)
		return (0);
	len = ft_strlen(s1);
	while (s1[j] != '\0' && ft_strchr(set, s1[j]) != NULL)
		j++;
	while (len > 0 && ft_strchr(set, s1[len - 1]) != NULL)
		len--;
	if (len == 0)
		p = (char *)malloc(sizeof(char));
	else
		p = (char *)malloc(sizeof(char) * (len - j + 1));
	if (p == NULL)
		return (NULL);
	return (p = ft_gp(j, len, s1, p));
}
