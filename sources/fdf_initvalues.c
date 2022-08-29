/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_initvalues.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:24:56 by bjimenez          #+#    #+#             */
/*   Updated: 2022/08/26 11:05:00 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libfdf.h"

t_datamap	*ft_init_datamap(void)
{
	t_datamap	*datamap;

	datamap = ft_calloc(1, sizeof(t_datamap));
	if (!datamap)
		ft_errors("Error datamap mem init");
	datamap->width = 0;
	datamap->height = 0;
	datamap->coord_list = NULL;
	datamap->color_list = NULL;
	datamap->z_min = 0;
	datamap->z_max = 0;
	datamap->z_diff = 0;
	return (datamap);
}

t_mlx	*ft_mlx_init(t_datamap *datamap)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ft_calloc(1, sizeof(t_mlx));
	if (!mlx)
		ft_errors("Error MLX mem init");
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		ft_errors("Error MLX init");
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "FdF");
	if (!mlx->win)
		ft_errors("Error MLX_window");
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!mlx->img)
		ft_errors("Error MLX_image");
	mlx->d_add = mlx_get_data_addr(mlx->img, &mlx->bit_per_pixel,
			&mlx->size_line, &mlx->endian);
	mlx->datamap = datamap;
	mlx->mouse = (t_mouse *)ft_calloc(1, sizeof(t_mouse));
	if (!mlx->mouse)
		ft_errors("Error MLX mem init");
	return (mlx);
}

t_view	*ft_view_init(t_datamap *datamap)
{
	t_view	*view;

	(void)datamap;
	view = (t_view *)ft_calloc(1, sizeof(t_view));
	if (!view)
		ft_errors("Error mem type view");
	view->x_angle = 0;
	view->y_angle = 0;
	view->z_angle = 0;
	view->z_factor = 1;
	view->xoffset = WIDTH / 2;
	view->yoffset = HEIGHT / 2;
	view->view = 'i';
	view->zoom = 1;
	view->show_c = 0;
	return (view);
}
