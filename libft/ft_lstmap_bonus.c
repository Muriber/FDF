/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:35:27 by bjimenez          #+#    #+#             */
/*   Updated: 2022/05/04 16:10:09 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*aux;

	if (lst == NULL)
		return (NULL);
	aux = NULL;
	while (lst != NULL)
	{
		n_lst = ft_lstnew((*f)(lst->content));
		if (n_lst == NULL)
		{
			ft_lstclear(&aux, del);
			return (NULL);
		}
		ft_lstadd_back(&aux, n_lst);
		lst = lst->next;
	}
	return (aux);
}
