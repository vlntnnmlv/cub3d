/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 16:27:01 by rmarguri          #+#    #+#             */
/*   Updated: 2020/10/27 13:51:55 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void		set_se(int *s, int *e, int wall_height, t_app *app)
{
	*s = -wall_height / 2 + app->config.h / 2;
	*e = wall_height / 2 + app->config.h / 2;
	*s = *s < 0 ? 0 : *s;
	*e = *e > app->config.h ? app->config.h : *e;
}

t_point		set_t(t_ray ray, t_fpoint pos, t_image tex)
{
	t_fpoint	wall;
	t_point		t;

	wall.y = pos.y + ray.perp_wall_dist * ray.dir.y;
	wall.x = pos.x + ray.perp_wall_dist * ray.dir.x;
	wall.y -= floor((wall.y));
	wall.x -= floor((wall.x));
	if (ray.side == 0)
		t.x = (int)(wall.y * (float)(tex.w));
	else
		t.x = (int)(wall.x * (float)(tex.w));
	if (ray.side == 0 && ray.dir.x > 0)
		t.x = tex.w - t.x;
	if (ray.side == 1 && ray.dir.y < 0)
		t.x = tex.w - t.x;
	t.y = 0;
	return (t);
}

void		set_draw(t_app *app, t_sprite *sprite)
{
	sprite->draw_s.y = -sprite->dim.y / 2 + app->config.h / 2;
	if (sprite->draw_s.y < 0)
		sprite->draw_s.y = 0;
	sprite->draw_e.y = sprite->dim.y / 2 + app->config.h / 2;
	if (sprite->draw_e.y >= app->config.h)
		sprite->draw_e.y = app->config.h - 1;
	sprite->draw_s.x = -sprite->dim.x / 2 + sprite->s_s_x;
	if (sprite->draw_s.x < 0)
		sprite->draw_s.x = 0;
	sprite->draw_e.x = sprite->dim.x / 2 + sprite->s_s_x;
	if (sprite->draw_e.x >= app->config.w)
		sprite->draw_e.x = app->config.w - 1;
}

void		set_s_pos(t_app *app, t_fpoint pos, t_fpoint *s_pos, int i)
{
	s_pos->x = app->config.sprites[i].x - pos.x;
	s_pos->y = app->config.sprites[i].y - pos.y;
}

void		set_transf(t_app *app, t_fpoint s_pos, t_fpoint *transf)
{
	float	inv_det;

	inv_det = 1.0 / (app->camera.plane.x * app->camera.p_dir.y - \
	app->camera.plane.y * app->camera.p_dir.x);
	transf->x = inv_det * (app->camera.p_dir.y * s_pos.x - \
	app->camera.p_dir.x * s_pos.y);
	transf->y = inv_det * (-app->camera.plane.y * s_pos.x + \
	app->camera.plane.x * s_pos.y);
}
