/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:12:52 by bjimenez          #+#    #+#             */
/*   Updated: 2022/08/25 12:24:20 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	ft_define_disp_i(t_draw_line *data)
{
	if (data->dy >= 0)
		data->disp_i_y = 1;
	else
	{
		data->dy *= -1;
		data->disp_i_y = -1;
	}
	if (data->dx >= 0)
		data->disp_i_x = 1;
	else
	{
		data->dx *= -1;
		data->disp_i_x = -1;
	}
}

void	ft_define_disp_r(t_draw_line *data)
{
	int	aux;

	if (data->dx >= data->dy)
	{
		data->disp_r_y = 0;
		data->disp_r_x = data->disp_i_x;
	}
	else
	{
		data->disp_r_x = 0;
		data->disp_r_y = data->disp_i_y;
		aux = data->dx;
		data->dx = data->dy;
		data->dy = aux;
	}
}

void	ft_define_adv(t_draw_line *data, int x1, int y1)
{
	data->x = x1;
	data->y = y1;
	data->adv_r = 2 * data->dy;
	data->adv = data->adv_r - data->dx;
	data->adv_i = data->adv - data->dx;
}

void	ft_define_type_adv(t_draw_line *data)
{
	if (data->adv >= 0)
	{
		data->x = data->x + data->disp_i_x;
		data->y = data->y + data->disp_i_y;
		data->adv = data->adv + data->adv_i;
	}
	else
	{
		data->x = data->x + data->disp_r_x;
		data->y = data->y + data->disp_r_y;
		data->adv = data->adv + data->adv_r;
	}
}

void	ft_bresenham(t_3dcoord c1, t_3dcoord c2, t_mlx *mlx)
{
	t_draw_line	data;
	int			p_height;

	p_height = HEIGHT;
	data.dy = (c2.y - c1.y);
	data.dx = (c2.x - c1.x);
	ft_define_disp_i(&data);
	ft_define_disp_r(&data);
	ft_define_adv(&data, c1.x, c1.y);
	if (mlx->view->show_c == 1)
		p_height = HEIGHT - 200;
	while (data.x != c2.x || data.y != c2.y)
	{
		if (data.x < WIDTH && data.x > 0 && data.y <= p_height && data.y >= 0)
			img_pix_put(mlx, data.x, data.y, ft_define_color(data, c1, c2));
		ft_define_type_adv(&data);
	}
}
