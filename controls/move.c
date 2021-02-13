/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 16:38:52 by rmarguri          #+#    #+#             */
/*   Updated: 2020/10/26 10:18:29 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"

int		check_collision(t_app *app, t_fpoint init)
{
	if (app->config.map[(int)app->camera.p.y][(int)init.x] == '1' || \
	app->config.map[(int)app->camera.p.y][(int)init.x] == '2')
		app->camera.p.y = init.y;
	if (app->config.map[(int)init.y][(int)app->camera.p.x] == '1' || \
	app->config.map[(int)init.y][(int)app->camera.p.x] == '2')
		app->camera.p.x = init.x;
	return (0);
}

int		move_collinear(t_app *app, int keycode)
{
	if (keycode == 13)
	{
		app->camera.p.x += app->camera.p_dir.x * MOVSPEED;
		app->camera.p.y += app->camera.p_dir.y * MOVSPEED;
	}
	if (keycode == 1)
	{
		app->camera.p.x -= app->camera.p_dir.x * MOVSPEED;
		app->camera.p.y -= app->camera.p_dir.y * MOVSPEED;
	}
	return (0);
}

int		move_ortogonal(t_app *app, int keycode)
{
	if (keycode == 0)
	{
		app->camera.p.x -= app->camera.plane.x * MOVSPEED / app->camera.fov;
		app->camera.p.y -= app->camera.plane.y * MOVSPEED / app->camera.fov;
	}
	if (keycode == 2)
	{
		app->camera.p.x += app->camera.plane.x * MOVSPEED / app->camera.fov;
		app->camera.p.y += app->camera.plane.y * MOVSPEED / app->camera.fov;
	}
	return (0);
}

int		move(int keycode, t_app *app)
{
	t_fpoint init;

	init = app->camera.p;
	move_collinear(app, keycode);
	move_ortogonal(app, keycode);
	check_collision(app, init);
	update_screen(app);
	update_window(app);
	return (0);
}
