/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_views.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:55:11 by bjimenez          #+#    #+#             */
/*   Updated: 2022/08/25 12:25:03 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	ft_rot_x_axis(double x_angle, int *y, int *z)
{
	int	y_aux;
	int	z_aux;

	y_aux = *y;
	z_aux = *z;
	*y = y_aux * cos(x_angle) - z_aux * sin(x_angle);
	*z = y_aux * sin(x_angle) + z_aux * cos(x_angle);
}

void	ft_rot_y_axis(double y_angle, int *x, int *z)
{
	int	x_aux;

	x_aux = *x;
	*x = x_aux * cos(y_angle) + *z * sin(y_angle);
	*z = -x_aux * sin(y_angle) + *z * cos(y_angle);
}

void	ft_rot_z_axis(double z_angle, int *x, int *y)
{
	int	y_aux;
	int	x_aux;

	y_aux = *y;
	x_aux = *x;
	*x = x_aux * cos(z_angle) - *y * sin(z_angle);
	*y = x_aux * sin(z_angle) + *y * cos(z_angle);
}

void	ft_isometric(int *x, int *y, int z)
{
	int	aux_x;
	int	aux_y;

	aux_x = *x;
	aux_y = *y;
	*x = (aux_x - aux_y) * cos(0.523599);
	*y = -z + (aux_x + aux_y) * sin(0.523599);
}
