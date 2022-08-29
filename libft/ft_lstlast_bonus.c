/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:05:36 by bjimenez          #+#    #+#             */
/*   Updated: 2022/05/04 16:09:56 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_n;

	last_n = lst;
	if (lst == NULL)
		return (NULL);
	while (last_n->next != NULL)
		last_n = last_n->next;
	return (last_n);
}
