/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 08:52:34 by bjimenez          #+#    #+#             */
/*   Updated: 2022/08/26 11:03:40 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libfdf.h"

int	ft_checkname(char *name)
{
	char	**str;

	str = ft_split(name, '.');
	if (str[1] && ft_strlen(str[1]) == 3 && ft_strncmp(str[1], "fdf", 3) == 0)
	{
		ft_free_d_ptr(str);
		return (1);
	}
	else
		ft_errors("Wrong file extension");
	return (-1);
}

int	main(int argc, char **argv)
{
	int				fd;
	t_datamap		*datamap;
	t_coord_list	*coord_list;
	t_mlx			*mlx;

	coord_list = NULL;
	if (argc == 2)
	{
		ft_checkname(argv[1]);
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			ft_errors("File open error");
		datamap = ft_init_datamap();
		ft_read_quad(fd, datamap, &coord_list);
		mlx = ft_mlx_init(datamap);
		mlx->view = ft_view_init(datamap);
		ft_coorcol_ls(&coord_list, datamap, mlx);
		ft_draw_data(datamap, mlx);
		ft_mlx_events(mlx);
		mlx_loop(mlx->mlx);
	}
	else
		perror("Wrong number of arguments");
	return (0);
}
