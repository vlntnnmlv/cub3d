/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:50:41 by rmarguri          #+#    #+#             */
/*   Updated: 2020/10/27 13:56:41 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void		draw_floor(int e, int x, t_app *app)
{
	int		y;
	t_point	where;

	y = e;
	while (y < app->config.h)
	{
		where.x = x;
		where.y = y;
		paint_pixel(&app->screen, where, app->config.f);
		y++;
	}
}

void		draw_skybox(t_app *app, t_ray ray, int x)
{
	t_point t;
	t_point where;
	float	step;
	float	tex_pos;

	where.x = x;
	step = 1.0 * app->skybox.h / app->screen.h;
	t.x = map_t(ang(ray.dir), 360, app->skybox.w);
	where.y = 0;
	tex_pos = 0;
	while (where.y < ray.s)
	{
		t.y = (int)tex_pos;
		tex_pos += step;
		paint_pixel(&app->screen, where, get_color(app->skybox, t.x, t.y));
		where.y++;
	}
}

void		draw_ceiling(t_ray ray, int x, t_app *app)
{
	int		y;
	t_point	where;

	if (app->controller.sky)
		draw_skybox(app, ray, x);
	else
	{
		y = 0;
		while (y < ray.s)
		{
			where.x = x;
			where.y = y;
			paint_pixel(&app->screen, where, app->config.c);
			y++;
		}
	}
}

void		line_tex(t_app *app, t_ray ray, t_fpoint pos, int x)
{
	t_point		t;
	float		step;
	float		tex_pos;
	int			color;
	t_point		where;

	set_se(&ray.s, &ray.e, ray.wall_height, app);
	t = set_t(ray, pos, ray.tex);
	step = 1.0 * ray.tex.h / ray.wall_height;
	tex_pos = (ray.s - app->config.h / 2 + ray.wall_height / 2) * step;
	draw_ceiling(ray, x, app);
	where.y = ray.s;
	where.x = x;
	while (where.y < ray.e)
	{
		t.y = (int)tex_pos;
		tex_pos += step;
		color = get_color(ray.tex, ray.tex.w - \
		(t.y == ray.tex.h - 1 && t.x == 0) - t.x, t.y);
		color = darken(color, (ray.perp_wall_dist * ray.dir.x * ray.step.x + \
		ray.perp_wall_dist * ray.dir.y * ray.step.y) / 1.2);
		paint_pixel(&app->screen, where, color);
		where.y++;
	}
	draw_floor(ray.e, x, app);
}

float		*draw_walls(t_app *app)
{
	t_ray		ray;
	t_fpoint	pos;
	float		*dist_b;
	int			x;

	pos = app->camera.p;
	dist_b = (float*)malloc(sizeof(float) * app->config.w);
	app->camera.plane = set_camera(app);
	x = 0;
	while (x < app->config.w)
	{
		charge_ray(app, &ray, pos, x);
		blast_ray(app, &ray);
		calc_wall(app, &ray, pos);
		choose_texture(app, &ray, pos);
		line_tex(app, ray, pos, x);
		dist_b[x] = ray.perp_wall_dist;
		x++;
	}
	return (dist_b);
}
