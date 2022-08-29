/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_menu_controls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:58:33 by bjimenez          #+#    #+#             */
/*   Updated: 2022/08/29 08:52:58 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libfdf.h"

void	ft_menu_rot(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 500, 920, 0x00000000,
		"Zoom  	-> Num_pad + / Num_pad - || Scroll Up/Down");
	mlx_string_put(mlx->mlx, mlx->win, 500, 950, 0x00000000,
		"Rotate	-> X axis: Num_pad 1 || Num_pad 2");
	mlx_string_put(mlx->mlx, mlx->win, 500, 980, 0x00000000,
		"      	   Y axis: Num_pad 4 || Num_pad 5");
	mlx_string_put(mlx->mlx, mlx->win, 500, 1010, 0x00000000,
		"      	   Z axis: Num_pad 7 || Num_pad 8");
	mlx_string_put(mlx->mlx, mlx->win, 500, 1040, 0x00000000,
		"      	   Free  : L_Click & Move mouse");
}

void	ft_menu_projection(t_mlx *mlx)
{		
	mlx_string_put(mlx->mlx, mlx->win, 1120, 920, 0x00000000,
		"Projection -> i : Isometric view");
	mlx_string_put(mlx->mlx, mlx->win, 1120, 950, 0x00000000,
		"              c : Cavalier view");
	mlx_string_put(mlx->mlx, mlx->win, 1120, 980, 0x00000000,
		"              f : Front view");
	mlx_string_put(mlx->mlx, mlx->win, 1120, 1010, 0x00000000,
		"              s : Side view");
	mlx_string_put(mlx->mlx, mlx->win, 1120, 1040, 0x00000000,
		"              u : Floor view");
}

void	ft_show_menu(t_mlx *mlx)
{
	if (mlx->view->show_c == 0)
		mlx_string_put(mlx->mlx, mlx->win, 10, 1000, 0x00FFFFFF,
			"Press Space to show CONTROLS");
	else
	{
		mlx_string_put(mlx->mlx, mlx->win, 20, 890, 0x00000000,
			"CONTROLS (press Space to hide controls)");
		mlx_string_put(mlx->mlx, mlx->win, 20, 920, 0x00000000,
			"Exit	-> Esc");
		mlx_string_put(mlx->mlx, mlx->win, 20, 950, 0x00000000,
			"Move	-> Main Pad Arrows");
		mlx_string_put(mlx->mlx, mlx->win, 20, 980, 0x00000000,
			"    	   R_Click & Move mouse");
		ft_menu_rot(mlx);
		ft_menu_projection(mlx);
	}
}
