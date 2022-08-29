/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:16:32 by bjimenez          #+#    #+#             */
/*   Updated: 2022/05/04 16:09:04 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_n;

	lst_n = *lst;
	if (*lst == NULL)
	{	
		*lst = new;
		return ;
	}
	lst_n = ft_lstlast(*lst);
	lst_n->next = new;
}
