/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:14:27 by bjimenez          #+#    #+#             */
/*   Updated: 2022/08/29 11:00:36 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFDF_H
# define LIBFDF_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"
# include <math.h>

# define WIDTH	1920
# define HEIGHT	1080
# define BASE_DATA1 "0123456789ABCDEF"
# define BASE_DATA2 "0123456789abcdef"

typedef struct s_mouse
{
	int	x;
	int	y;
	int	prev_x;
	int	prev_y;
	int	click;
}				t_mouse;

typedef struct s_view
{
	double	x_angle;
	double	y_angle;
	double	z_angle;
	int		zoom;
	float	z_factor;
	int		xoffset;
	int		yoffset;
	char	view;
	int		show_c;
}				t_view;

typedef struct s_datamap
{
	int	width;
	int	height;
	int	*coord_list;
	int	*color_list;
	int	z_min;
	int	z_max;
	int	z_diff;
}				t_datamap;

typedef struct s_coord_list
{
	int					z;
	int					color;
	struct s_coord_list	*next;
}				t_coord_list;

void			ft_errors(char *strerr);
void			ft_read_quad(int fd, t_datamap *datamap,
					t_coord_list **coord_list);
t_datamap		*ft_init_datamap(void);
int				ft_check_nbr(char *nbr, int base);
void			ft_lstadd(t_coord_list **lst, t_coord_list *new);
int				ft_atoi_base(const char *str, int base);
void			ft_free_d_ptr(char **ptr);

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*d_add;
	int			bit_per_pixel;
	int			size_line;
	int			endian;
	t_datamap	*datamap;
	t_view		*view;
	t_mouse		*mouse;
}				t_mlx;

t_mlx			*ft_mlx_init(t_datamap *datamap);
void			ft_zoom_define(int zmax, int zmin, t_datamap *datamap,
					t_mlx *mlx);
void			ft_coorcol_ls(t_coord_list **coord_list, t_datamap *datamap,
					t_mlx *mlx);
t_coord_list	*ft_first(t_coord_list **coord_list);

t_view			*ft_view_init(t_datamap *datamap);

typedef struct s_3dcoord
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_3dcoord;

typedef struct s_draw_line
{
	int	dy;
	int	dx;
	int	disp_i_y;
	int	disp_i_x;
	int	disp_r_x;
	int	disp_r_y;
	int	x;
	int	y;
	int	adv;
	int	adv_r;
	int	adv_i;
}				t_draw_line;

int				ft_draw_data(t_datamap *datamap, t_mlx *mlx);
void			ft_bresenham(t_3dcoord c1, t_3dcoord c2, t_mlx *mlx);
int				ft_v_abs(int x);
void			ft_mlx_events(t_mlx *mlx);
int				ft_selkey(int keycode, void *ptr);
void			ft_xy_move(t_mlx *mlx, int keycode);
void			img_pix_put(t_mlx *mlx, int x, int y, int color);
int				ft_close(void *ptr);
void			ft_isometric(int *x, int *y, int z);
void			ft_rot_x_axis(double x_angle, int *y, int *z);
void			ft_rot_y_axis(double y_angle, int *x, int *z);
void			ft_rot_z_axis(double z_angle, int *x, int *y);
void			ft_rotate(t_mlx *mlx, int keycode);
void			ft_cavalier(int *x, int *y, int z);
void			ft_front_view(int *x, int *y, int z);
void			ft_side_view(int *x, int *y, int z);
void			ft_floor_view(int *x, int *y);
void			ft_zoom(t_mlx *mlx, int keycode);
void			ft_zoom_view(int zoom, int *x, int *y);
int				ft_mouse_click_scroll(int keycode, int x, int y, void *ptr);
int				ft_mouse_move(int x, int y, void *ptr);
int				ft_mouse_no_click(int keycode, int x, int y, void *ptr);
int				ft_define_color(t_draw_line data, t_3dcoord c1, t_3dcoord c2);
int				ft_get_color(int range_color);
void			ft_show_menu(t_mlx *mlx);
int				ft_strcmp(char *str, char *ptr);

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
	int	g1;
	int	b1;
	int	g2;
	int	b2;
}				t_rgb;

#endif
