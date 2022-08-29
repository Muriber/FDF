/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:22:52 by bjimenez          #+#    #+#             */
/*   Updated: 2022/08/29 10:57:31 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int	ft_check_nbr(char *nbr, int base)
{
	int		i;
	int		j;

	i = -1;
	if (base == 16 && nbr[0] == '0' && nbr[1] == 'x')
		nbr = nbr + 2;
	else if (base == 16 && (nbr[0] != '0' || nbr[1] != 'x'))
		return (-1);
	while (nbr[++i] != '\0' && nbr[i] != '\n')
	{
		if (nbr[i] == '-' && nbr[i + 1] != '-')
			i++;
		else if (nbr[i] == '-' && nbr[i + 1] == '-')
			return (-1);
		j = 0;
		while ((nbr[i] != BASE_DATA1[j] && nbr[i] != BASE_DATA2[j])
			&& BASE_DATA1[j] != '\0' && j < base)
			j++;
		if (j >= base)
			return (-1);
	}
	return (0);
}

void	ft_lstadd(t_coord_list **coord_list, t_coord_list *new_z)
{
	if (coord_list)
	{
		if (new_z)
			new_z->next = *coord_list;
		*coord_list = new_z;
	}
}

t_coord_list	*ft_first(t_coord_list **coords_list)
{
	t_coord_list	*first;

	first = NULL;
	if (coords_list && *coords_list)
	{
		first = *coords_list;
		*coords_list = (*coords_list)->next;
	}
	return (first);
}

void	ft_free_d_ptr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

int	ft_strcmp(char *str, char *ptr)
{
	size_t	i;

	i = 0;
	while (str [i] == ' ')
		i++;
	if (str[i] == ptr[i] && str[i] != '\0')
		return (-1);
	else
		return (0);
}
