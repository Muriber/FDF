/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_quad.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:53:04 by bjimenez          #+#    #+#             */
/*   Updated: 2022/08/26 12:35:08 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

t_coord_list	*ft_new_point(char *data_line)
{
	t_coord_list	*new_z;
	char			**zc_val;

	new_z = (t_coord_list *)malloc(sizeof (t_coord_list));
	zc_val = ft_split(data_line, ',');
	if (!new_z || !zc_val)
		ft_errors("Wrong map reading");
	if (ft_check_nbr(zc_val[0], 10) == -1)
		ft_errors("Wrong Z-value format");
	else if (zc_val[1] && ft_check_nbr(zc_val[1], 16) == -1)
		ft_errors("Wrong Z-color format");
	if (zc_val[0])
		new_z->z = ft_atoi_base(zc_val[0], 10);
	if (zc_val[1])
		new_z->color = ft_atoi_base(zc_val[1], 16);
	else
		new_z->color = -1;
	new_z->next = NULL;
	ft_free_d_ptr(zc_val);
	return (new_z);
}

void	ft_verif_data_line(char **data_line, t_coord_list **coord_list)
{
	while (*data_line != 0)
	{
		if (ft_strcmp(*data_line, "\n") == 0)
			ft_lstadd(coord_list, ft_new_point(*(data_line)));
		data_line++;
	}
}

int	ft_map_width(char **data_line)
{
	int		width;

	width = 0;
	while (data_line[width] != 0 && *data_line[width] != '\n')
		width++;
	return (width);
}

void	ft_err_map(char *str, t_datamap *datamap, char *line, char **data_line)
{
	free (datamap);
	free (line);
	if (data_line)
		ft_free_d_ptr(data_line);
	ft_errors(str);
}

void	ft_read_quad(int fd, t_datamap *datamap, t_coord_list **coord_list)
{
	char	*line;
	char	**data_line;
	int		width;

	width = 0;
	data_line = NULL;
	line = get_next_line(fd);
	if (!line)
		ft_err_map("Wrong map data", datamap, line, data_line);
	while (line)
	{
		data_line = ft_split(line, ' ');
		width = ft_map_width(data_line);
		if (datamap->height == 0)
			datamap->width = width;
		else if (datamap->width != width || !data_line)
			ft_err_map("Wrong map data", datamap, line, data_line);
		ft_verif_data_line(data_line, coord_list);
		free (line);
		ft_free_d_ptr(data_line);
		line = get_next_line(fd);
		datamap->height++;
	}
	close (fd);
	free (line);
}
