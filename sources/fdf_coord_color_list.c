/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_coord_color_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:20:52 by bjimenez          #+#    #+#             */
/*   Updated: 2022/08/25 12:22:40 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	ft_zoom_define(int zmax, int zmin, t_datamap *datamap, t_mlx *mlx)
{
	int	zoom_width;
	int	zoom_height;

	datamap->z_max = zmax;
	datamap->z_min = zmin;
	datamap->z_diff = datamap->z_max - datamap->z_min;
	zoom_width = (WIDTH / datamap->width) / 3;
	zoom_height = (HEIGHT / datamap->height) / 3;
	if (datamap->z_diff != 0 && (HEIGHT / datamap->z_diff) / 2 < zoom_height
		&& HEIGHT / datamap->z_diff / 2 < zoom_width)
		mlx->view->zoom = ((HEIGHT / datamap->z_diff) / 2);
	else if (zoom_width != 0 && zoom_width <= zoom_height)
		mlx->view->zoom = zoom_width;
	else if (zoom_height != 0 && zoom_height <= zoom_width)
		mlx->view->zoom = zoom_height;
	else
		mlx->view->zoom = 1;
}

void	ft_coorcol_ls(t_coord_list **coord_list, t_datamap *datamap, t_mlx *mlx)
{
	t_coord_list	*aux;
	int				size_list;
	int				z[2];

	size_list = (datamap->width * datamap->height) - 1;
	datamap->coord_list = (int *)malloc(sizeof(int) * (size_list + 1));
	datamap->color_list = (int *)malloc(sizeof(int) * (size_list + 1));
	if (!datamap->coord_list || !datamap->color_list)
		ft_errors("Error mem. Z values");
	aux = ft_first(coord_list);
	z[0] = aux->z;
	z[1] = aux->z;
	while (size_list >= 0 && aux)
	{
		datamap->coord_list[size_list] = aux->z;
		datamap->color_list[size_list] = aux->color;
		if (z[0] > datamap->coord_list[size_list])
			z[0] = datamap->coord_list[size_list];
		if (z[1] < datamap->coord_list[size_list])
			z[1] = datamap->coord_list[size_list];
		free (aux);
		aux = ft_first(coord_list);
		size_list--;
	}
	ft_zoom_define(z[1], z[0], datamap, mlx);
}
