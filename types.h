/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:20:30 by rmarguri          #+#    #+#             */
/*   Updated: 2020/10/28 16:09:06 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "libft/libft.h"

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_fpoint
{
	float	x;
	float	y;
}				t_fpoint;

typedef struct	s_color
{
	int	t;
	int	r;
	int	g;
	int b;
}				t_color;

typedef struct	s_image
{
	void	*img_ptr;
	char	*img_data;
	int		bpp;
	int		line;
	int		endian;
	int		w;
	int		h;
}				t_image;

typedef	struct	s_sprite
{
	int			s_s_x;
	float		x;
	float		y;
	t_fpoint	pos;
	t_fpoint	transf;
	t_point		dim;
	t_point		draw_s;
	t_point		draw_e;
	t_image		tex;
}				t_sprite;

typedef struct	s_ray
{
	t_fpoint	dir;
	t_fpoint	side_dist;
	t_fpoint	d_dist;
	t_point		m;
	t_point		step;
	float		dist;
	float		perp_wall_dist;
	int			wall_height;
	int			side;
	int			s;
	int			e;
	t_image		tex;
}				t_ray;

typedef struct	s_camera
{
	t_fpoint	plane;
	t_fpoint	p;
	t_fpoint	p_dir;
	float		fov;
}				t_camera;

typedef struct	s_config
{
	int			w;
	int			h;
	int			n_sprites;
	t_sprite	*sprites;
	t_image		*textures;
	int			f;
	int			c;
	char		**map;
	int			rows;
	int			cols;
}				t_config;

typedef	struct	s_cunit
{
	int mv;
	int rt;
	int save;
	int	map;
	int	sky;
}				t_cunit;

typedef struct	s_app
{
	void			*mlx_ptr;
	void			*mlx_win;
	t_config		config;
	t_image			screen;
	t_camera		camera;
	char			*save_path;
	int				save_fd;
	int				stdw;
	int				stdh;
	t_image			skybox;
	t_cunit			controller;
}				t_app;

#endif
