/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:22:45 by bjimenez          #+#    #+#             */
/*   Updated: 2022/05/04 16:10:20 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;

	size = 0;
	if (lst == NULL)
		return (size);
	while (lst->next != NULL)
	{
		size++;
		lst = lst->next;
	}
	if (lst->next == NULL)
		size++;
	return (size);
}
