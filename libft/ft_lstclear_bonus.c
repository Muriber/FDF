/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:41:12 by bjimenez          #+#    #+#             */
/*   Updated: 2022/05/04 16:09:24 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*t_aux;

	t_aux = *lst;
	if (*lst == NULL)
		return ;
	while (t_aux != NULL)
	{
		t_aux = t_aux->next;
		ft_lstdelone(*lst, del);
		*lst = t_aux;
	}
	*lst = NULL;
}
