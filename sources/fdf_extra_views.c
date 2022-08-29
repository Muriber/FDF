/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_extra_views.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:42:47 by bjimenez          #+#    #+#             */
/*   Updated: 2022/08/25 12:26:52 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	ft_cavalier(int *x, int *y, int z)
{
	int	aux_x;
	int	aux_y;

	aux_x = *x;
	aux_y = *y;
	*y = -z + (aux_y * 0.5);
	*x = aux_x - (aux_y * 1);
}

void	ft_front_view(int *x, int *y, int z)
{
	int	aux_x;
	int	aux_y;

	aux_x = *x;
	aux_y = *y;
	*y = -z;
	*x = aux_x;
}

void	ft_side_view(int *x, int *y, int z)
{
	int	aux_x;
	int	aux_y;

	aux_x = *x;
	aux_y = *y;
	*y = -z;
	*x = -aux_y;
}

void	ft_floor_view(int *x, int *y)
{
	int	aux_x;
	int	aux_y;

	aux_x = *x;
	aux_y = *y;
	*y = aux_y;
	*x = aux_x;
}
