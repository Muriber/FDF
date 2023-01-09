/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:19:04 by bjimenez          #+#    #+#             */
/*   Updated: 2022/04/28 11:34:44 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	ssrc;
	size_t	s;

	ssrc = ft_strlen(src);
	s = 0;
	if (dstsize == 0)
		return (ssrc);
	while (s < dstsize - 1 && *src != '\0')
	{
		dst[s] = *src;
		s++;
		src++;
	}
	dst[s] = '\0';
	return (ssrc);
}
