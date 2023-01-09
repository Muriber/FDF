/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:22:23 by bjimenez          #+#    #+#             */
/*   Updated: 2022/04/28 11:33:10 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	sdst;
	size_t	ssrc;
	size_t	s;

	sdst = ft_strlen(dst);
	ssrc = ft_strlen(src);
	if (dstsize <= sdst)
		return (dstsize + ssrc);
	dstsize--;
	s = sdst;
	while (sdst < dstsize && *src != '\0')
	{
		dst[sdst] = *src;
		sdst++;
		src++;
	}
	dst[sdst] = '\0';
	return (s + ssrc);
}
