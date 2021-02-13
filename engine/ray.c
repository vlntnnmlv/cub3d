/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 19:29:56 by rmarguri          #+#    #+#             */
/*   Updated: 2020/10/05 17:39:09 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void		charge_ray(t_app *app, t_ray *ray, t_fpoint pos, int x)
{
	ray->dir = set_ray(app, x);
	ray->m.x = (int)pos.x;
	ray->m.y = (int)pos.y;
	ray->d_dist = set_ddist(ray->dir);
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (pos.x - ray->m.x) * ray->d_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->m.x + 1 - pos.x) * ray->d_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (pos.y - ray->m.y) * ray->d_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->m.y + 1 - pos.y) * ray->d_dist.y;
	}
}

void		blast_ray(t_app *app, t_ray *ray)
{
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->d_dist.x;
			ray->m.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->d_dist.y;
			ray->m.y += ray->step.y;
			ray->side = 1;
		}
		if (app->config.map[ray->m.y][ray->m.x] == '1')
			hit = 1;
	}
}

void		choose_texture(t_app *app, t_ray *ray, t_fpoint pos)
{
	if (ray->side == 0)
	{
		if (pos.x + ray->perp_wall_dist * ray->dir.x > ray->m.x + 0.5)
			ray->tex = app->config.textures[3];
		else
			ray->tex = app->config.textures[2];
	}
	else
	{
		if (pos.y + ray->perp_wall_dist * ray->dir.y > ray->m.y + 0.5)
			ray->tex = app->config.textures[1];
		else
			ray->tex = app->config.textures[0];
	}
}

void		calc_wall(t_app *app, t_ray *ray, t_fpoint pos)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->m.x - pos.x + \
		(1. - ray->step.x) / 2.) / ray->dir.x;
	else
		ray->perp_wall_dist = (ray->m.y - pos.y + \
		(1. - ray->step.y) / 2.) / ray->dir.y;
	ray->wall_height = (int)(app->config.h / ray->perp_wall_dist);
}
