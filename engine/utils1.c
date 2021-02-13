/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:47:55 by rmarguri          #+#    #+#             */
/*   Updated: 2020/10/19 17:14:11 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void		set_sprite(t_app *app, t_sprite *sprite, t_fpoint pos, int i)
{
	set_s_pos(app, pos, &sprite->pos, i);
	set_transf(app, sprite->pos, &sprite->transf);
	sprite->s_s_x = (int)((app->config.w / 2) * (1 + sprite->transf.x / \
	sprite->transf.y));
	sprite->dim.x = abs((int)(app->config.h / (sprite->transf.y)));
	sprite->dim.y = abs((int)(app->config.h / sprite->transf.y));
	set_draw(app, sprite);
}

t_fpoint	set_camera(t_app *app)
{
	t_fpoint	plane;
	t_fpoint	p_dir;

	p_dir = app->camera.p_dir;
	plane.x = -app->camera.fov * p_dir.y;
	plane.y = app->camera.fov * p_dir.x;
	return (plane);
}

t_fpoint	set_ray(t_app *app, int x)
{
	float		camera_x;
	t_fpoint	ray_dir;
	t_fpoint	plane;

	plane = app->camera.plane;
	camera_x = 2 * x / (float)app->config.w - 1;
	ray_dir.x = app->camera.p_dir.x + plane.x * camera_x;
	ray_dir.y = app->camera.p_dir.y + plane.y * camera_x;
	return (ray_dir);
}

t_fpoint	set_ddist(t_fpoint ray_dir)
{
	t_fpoint	d_dist;

	if (ray_dir.y == 0)
		d_dist.x = 0;
	else if (ray_dir.x == 0)
		d_dist.x = 1;
	else
		d_dist.x = fabs(1 / ray_dir.x);
	if (ray_dir.x == 0)
		d_dist.y = 0;
	else if (ray_dir.y == 0)
		d_dist.y = 1;
	else
		d_dist.y = fabs(1 / ray_dir.y);
	return (d_dist);
}

float		sq_dist(t_sprite sprite, t_fpoint pos)
{
	return (sqrt((pow(pos.x - sprite.x, 2) + pow(pos.y - sprite.y, 2))));
}
