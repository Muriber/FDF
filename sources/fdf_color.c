/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:51:22 by bjimenez          #+#    #+#             */
/*   Updated: 2022/08/25 12:23:24 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int	ft_v_abs(int x)
{
	if (x < 0)
		return (x * (-1));
	else
		return (x);
}

int	ft_define_tone(int color1, int color2, double range_color)
{
	t_rgb	rgb;

	rgb.r = 255;
	rgb.g1 = color1 >> 8;
	rgb.g1 = rgb.g1 & 0xFF;
	rgb.b1 = color1 & 0xFF;
	rgb.g2 = color2 >> 8;
	rgb.g2 = rgb.g2 & 0xFF;
	rgb.b2 = color2 & 0xFF;
	rgb.g = rgb.g1 + ((rgb.g2 - rgb.g1) * range_color) / 100;
	rgb.b = rgb.b1 + ((rgb.b2 - rgb.b1) * range_color) / 100;
	return ((rgb.r << 16) | (rgb.g << 8) | rgb.b);
}

int	ft_define_color(t_draw_line data, t_3dcoord c1,	t_3dcoord c2)
{
	double	range_color;
	int		color;

	if (c1.color == c2.color)
		return (c1.color);
	if (data.dx > data.dy)
	{
		if (c2.x - c1.x == 0)
			range_color = ft_v_abs(data.x - c1.x) * 100;
		else
			range_color = ft_v_abs(data.x - c1.x) * 100 / ft_v_abs(c2.x - c1.x);
	}
	else
	{
		if (c2.y - c1.y == 0)
			range_color = ft_v_abs(data.y - c1.y) * 100;
		else
			range_color = (data.y - c1.y) * 100 / ft_v_abs(c2.y - c1.y);
	}
	color = ft_define_tone(c1.color, c2.color, range_color);
	return (color);
}

int	ft_get_color(int range_color)
{
	int	r;
	int	g;
	int	b;

	if (range_color == 0)
		return (0xFFFFFF);
	else
		r = 255;
		g = (255 * (100 - range_color)) / 100;
		b = (255 * (100 - range_color)) / 100;
	return ((r << 16) | (g << 8) | b);
}
