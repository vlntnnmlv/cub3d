/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 19:17:27 by rmarguri          #+#    #+#             */
/*   Updated: 2020/10/19 17:24:00 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# define DEG 3.14/180

# define MINISQUARE 5
# define RED 0xFF0000
# define TOXICGREEN 0x12FF43
# define BLUE 0x0000FF

# define BIGD 15
# define SMLD 5

# define PERP_DIST(ray) ray.perp_wall_dist
# define DIST(sprite) sq_dist(sprite, app->camera.p)

# include <math.h>
# include "../mlx_mms/mlx.h"
# include "../types.h"
# include "../libft/libft.h"

t_fpoint			set_camera(t_app *app);
t_fpoint			set_ray(t_app *app, int x);
t_fpoint			set_ddist(t_fpoint ray_dir);
void				set_se(int *s, int *e, int wall_height, t_app *app);
t_point				set_t(t_ray ray, t_fpoint pos, t_image tex);

void				set_draw(t_app *app, t_sprite *sprite);
void				set_s_pos(t_app *app, t_fpoint pos, t_fpoint *s_pos, int i);
void				set_transf(t_app *app, t_fpoint s_pos, t_fpoint *transf);
void				set_sprite(t_app *app, t_sprite *sprite, \
					t_fpoint pos, int i);

void				charge_ray(t_app *app, t_ray *ray, t_fpoint pos, int x);
void				blast_ray(t_app *app, t_ray *ray);
void				calc_wall(t_app *app, t_ray *ray, t_fpoint pos);
void				choose_texture(t_app *app, t_ray *ray, t_fpoint pos);

float				*draw_walls(t_app *app);
void				line(t_app *app, t_ray ray, int x);
void				line_tex(t_app *app, t_ray ray, t_fpoint pos, int x);
unsigned int		get_color(t_image tex, int x, int y);

void				sort_sprites(t_app *app, t_sprite *sprites, t_fpoint pos);
void				draw_sprites(t_app *app, const t_fpoint pos, float *dist_b);

float				sq_dist(t_sprite sprite, t_fpoint pos);

void				draw_minimap(t_app *app);
void				update_sprites(t_app *app);

int					get_t(int trgb);
int					get_r(int trgb);
int					get_g(int trgb);
int					get_b(int trgb);
int					darken(int color, float perp);
int					get_trgb(int t, int r, int g, int b);
void				paint_pixel(t_image *image, \
					t_point where, unsigned int color);

int					map_t(float x, float m1, int m2);
float				ang(t_fpoint v);

#endif
