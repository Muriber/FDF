/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_drawdata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:02:32 by bjimenez          #+#    #+#             */
/*   Updated: 2022/08/26 11:05:10 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libfdf.h"

void	img_pix_put(t_mlx *mlx, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = mlx->bit_per_pixel - 8;
	pixel = mlx->d_add + (y * mlx->size_line + x * (mlx->bit_per_pixel / 8));
	while (i >= 0)
	{
		if (mlx->endian != 0)
			*pixel = (color >> i) & 0xFF;
		else
			*pixel = (color >> (mlx->bit_per_pixel - 8 - i)) & 0xFF;
		i -= 8;
		pixel++;
	}
}

t_3dcoord	ft_view(t_3dcoord xypos, t_mlx *mlx)
{
	ft_rot_x_axis(mlx->view->x_angle, &xypos.y, &xypos.z);
	ft_rot_y_axis(mlx->view->y_angle, &xypos.x, &xypos.z);
	ft_rot_z_axis(mlx->view->z_angle, &xypos.x, &xypos.y);
	if (mlx->view->view == 'i')
		ft_isometric(&xypos.x, &xypos.y, xypos.z);
	else if (mlx->view->view == 'c')
		ft_cavalier(&xypos.x, &xypos.y, xypos.z);
	else if (mlx->view->view == 'f')
		ft_front_view(&xypos.x, &xypos.y, xypos.z);
	else if (mlx->view->view == 's')
		ft_side_view(&xypos.x, &xypos.y, xypos.z);
	else if (mlx->view->view == 'u')
		ft_floor_view(&xypos.x, &xypos.y);
	xypos.x = mlx->view->xoffset + xypos.x;
	xypos.y = mlx->view->yoffset + xypos.y;
	return (xypos);
}

t_3dcoord	ft_3dpoint(int x, int y, t_datamap datamap, int zoom)
{
	t_3dcoord	xypos;
	int			i;

	i = (y * datamap.width) + x;
	xypos.z = datamap.coord_list[i] * zoom;
	xypos.x = x * zoom;
	xypos.y = y * zoom;
	if (datamap.color_list[i] == -1)
	{
		if (datamap.z_diff != 0)
			xypos.color = ft_get_color((datamap.coord_list[i] - datamap.z_min)
					* 100 / datamap.z_diff);
		else
			xypos.color = ft_get_color((datamap.coord_list[i] - datamap.z_min)
					* 100);
	}
	else
		xypos.color = datamap.color_list[i];
	return (xypos);
}

void	ft_render_background(t_mlx *mlx)
{
	int	*image;
	int	i;

	ft_bzero(mlx->d_add, (mlx->bit_per_pixel / 8) * WIDTH * HEIGHT);
	image = (int *)(mlx->d_add);
	i = 0;
	while (i < HEIGHT * WIDTH)
	{
		if (i > ((HEIGHT - 200) * WIDTH) && mlx->view->show_c == 1)
			image[i] = 0x00424242;
		else if (i > ((HEIGHT - 200) * WIDTH) && mlx->view->show_c == 0)
			image[i] = 0x00000000;
		else
			image[i] = 0x00000000;
		i++;
	}
}

int	ft_draw_data(t_datamap *datamap, t_mlx *mlx)
{
	int	x;
	int	y;
	int	zoom;

	zoom = mlx->view->zoom;
	ft_render_background(mlx);
	y = 0;
	while (y < datamap->height)
	{
		x = 0;
		while (x < datamap->width)
		{
			if (x != mlx->datamap->width - 1)
				ft_bresenham(ft_view(ft_3dpoint(x, y, *datamap, zoom), mlx),
					ft_view(ft_3dpoint(x + 1, y, *datamap, zoom), mlx), mlx);
			if (y != mlx->datamap->height - 1)
				ft_bresenham(ft_view(ft_3dpoint(x, y, *datamap, zoom), mlx),
					ft_view(ft_3dpoint(x, y + 1, *datamap, zoom), mlx), mlx);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	ft_show_menu(mlx);
	return (0);
}
