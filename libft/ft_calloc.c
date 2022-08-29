/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:38:52 by bjimenez          #+#    #+#             */
/*   Updated: 2022/04/29 13:28:59 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (count == __SIZE_MAX__ && size > 1)
		return (NULL);
	else if (size == __SIZE_MAX__ && count > 1)
		return (NULL);
	p = malloc(size * count);
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, size * count);
	return (p);
}
