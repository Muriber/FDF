/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_move_rot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:02:10 by bjimenez          #+#    #+#             */
/*   Updated: 2022/08/26 13:18:35 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int	ft_mouse_click_scroll(int keycode, int x, int y, void *ptr)
{
	t_mlx	*mlx;

	(void)x;
	(void)y;
	mlx = (t_mlx *)ptr;
	if (keycode == 5 || keycode == 4)
		ft_zoom(mlx, keycode);
	else if (keycode == 1)
		mlx->mouse->click = 1;
	else if (keycode == 2)
		mlx->mouse->click = 2;
	return (0);
}

int	ft_mouse_no_click(int keycode, int x, int y, void *ptr)
{
	t_mlx	*mlx;

	(void)x;
	(void)y;
	(void)keycode;
	mlx = (t_mlx *)ptr;
	mlx->mouse->click = 0;
	return (0);
}

void	ft_xy_move(t_mlx *mlx, int keycode)
{
	if (keycode == 123)
		mlx->view->xoffset -= 10;
	else if (keycode == 124)
		mlx->view->xoffset += 10;
	else if (keycode == 125)
		mlx->view->yoffset += 10;
	else if (keycode == 126)
		mlx->view->yoffset -= 10;
	ft_draw_data(mlx->datamap, mlx);
}

int	ft_mouse_move(int x, int y, void *ptr)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)ptr;
	mlx->mouse->prev_x = mlx->mouse->x;
	mlx->mouse->prev_y = mlx->mouse->y;
	mlx->mouse->x = x;
	mlx->mouse->y = y;
	if (mlx->mouse->click == 1)
	{
		mlx->view->z_angle -= (x - mlx->mouse->prev_x) * 0.015;
		mlx->view->x_angle -= (y - mlx->mouse->prev_y) * 0.015;
		ft_draw_data(mlx->datamap, mlx);
	}
	else if (mlx->mouse->click == 2)
	{
		mlx->view->xoffset += (x - mlx->mouse->prev_x);
		mlx->view->yoffset += (y - mlx->mouse->prev_y);
		ft_draw_data(mlx->datamap, mlx);
	}
	return (0);
}

void	ft_rotate(t_mlx *mlx, int keycode)
{
	if (keycode == 83)
		mlx->view->x_angle += 0.02;
	if (keycode == 84)
		mlx->view->x_angle -= 0.02;
	if (keycode == 86)
		mlx->view->y_angle += 0.02;
	if (keycode == 87)
		mlx->view->y_angle -= 0.02;
	if (keycode == 89)
		mlx->view->z_angle += 0.02;
	if (keycode == 91)
		mlx->view->z_angle -= 0.02;
	ft_draw_data(mlx->datamap, mlx);
}
