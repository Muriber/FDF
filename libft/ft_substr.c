/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:49:10 by bjimenez          #+#    #+#             */
/*   Updated: 2022/05/12 10:05:27 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	count;
	char			*ps;
	unsigned long	indx;
	unsigned long	nlen;

	indx = 0;
	if (!s)
		return (0);
	nlen = ft_strlen(s);
	if (start > nlen)
		return (ft_calloc(1, 1));
	if (nlen - start > 0 && nlen > len)
		nlen = len;
	ps = (char *)malloc((sizeof(char) * (nlen + 1)));
	if (ps == NULL)
		return (NULL);
	count = len + start;
	while (s[start + indx] != '\0' && start < count && indx < len
		&& start <= ft_strlen(s))
	{
		ps[indx] = s[start + indx];
		indx++;
	}
	ps[indx] = '\0';
	return (ps);
}
