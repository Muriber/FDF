/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 11:50:08 by bjimenez          #+#    #+#             */
/*   Updated: 2022/08/29 12:51:39 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"
#include "mlx.h"

void	ft_t_view(t_mlx *mlx, int keycode)
{
	if (keycode == 3)
		mlx->view->view = 'f';
	else if (keycode == 34)
		mlx->view->view = 'i';
	else if (keycode == 8)
		mlx->view->view = 'c';
	else if (keycode == 1)
		mlx->view->view = 's';
	else if (keycode == 32)
		mlx->view->view = 'u';
	mlx->view->x_angle = 0;
	mlx->view->y_angle = 0;
	mlx->view->z_angle = 0;
	ft_draw_data(mlx->datamap, mlx);
}

void	ft_zoom(t_mlx *mlx, int keycode)
{
	if (keycode == 69 || keycode == 4)
		mlx->view->zoom++;
	if ((keycode == 78 || keycode == 5) && mlx->view->zoom > 1)
		mlx->view->zoom--;
	ft_draw_data(mlx->datamap, mlx);
}

int	ft_selkey(int keycode, void *ptr)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ptr;
	if (keycode == 53)
		ft_close(mlx);
	else if (keycode == 123 || keycode == 124 || keycode == 125
		|| keycode == 126)
		ft_xy_move(mlx, keycode);
	else if (keycode == 3 || keycode == 34 || keycode == 8
		|| keycode == 1 || keycode == 32)
		ft_t_view(mlx, keycode);
	else if (keycode == 83 || keycode == 84 || keycode == 86
		|| keycode == 87 || keycode == 89 || keycode == 91)
		ft_rotate(mlx, keycode);
	else if (keycode == 69 || keycode == 78)
		ft_zoom(mlx, keycode);
	else if (keycode == 49)
	{
		if (mlx->view->show_c == 0)
			mlx->view->show_c = 1;
		else
			mlx->view->show_c = 0;
		ft_draw_data(mlx->datamap, mlx);
	}
	return (0);
}

int	ft_close(void *ptr)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ptr;
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	free (mlx->datamap->color_list);
	free (mlx->datamap->coord_list);
	free (mlx->view);
	free (mlx->datamap);
	free (mlx->mouse);
	free (mlx);
	exit (0);
	return (0);
}

void	ft_mlx_events(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 0, ft_selkey, mlx);
	mlx_hook(mlx->win, 17, 0, ft_close, mlx);
	mlx_hook(mlx->win, 4, 0, ft_mouse_click_scroll, mlx);
	mlx_hook(mlx->win, 5, 0, ft_mouse_no_click, mlx);
	mlx_hook(mlx->win, 6, 0, ft_mouse_move, mlx);
}
