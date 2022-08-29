/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:52:03 by bjimenez          #+#    #+#             */
/*   Updated: 2022/04/28 11:37:55 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		r;

	i = 0;
	if (n == 0)
		r = 0;
	else
	{
		while (s1[i] == s2[i] && s1[i] != '\0' && i < n - 1)
		{
			i++;
		}
		r = (unsigned char)s1[i] - (unsigned char)s2[i];
	}
	return (r);
}
