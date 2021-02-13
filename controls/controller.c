/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 16:44:18 by rmarguri          #+#    #+#             */
/*   Updated: 2020/10/19 14:49:25 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"

int		update_screen(t_app *app)
{
	float	*dist;

	dist = draw_walls(app);
	draw_sprites(app, app->camera.p, dist);
	if (app->controller.map)
		draw_minimap(app);
	free(dist);
	return (0);
}

int		update_window(t_app *app)
{
	mlx_put_image_to_window(app->mlx_ptr, app->mlx_win, \
	app->screen.img_ptr, 0, 0);
	return (0);
}

int		controller(t_app *app)
{
	if (app->controller.mv != -1)
		move(app->controller.mv, app);
	if (app->controller.rt != -1)
		rotate(app->controller.rt, app);
	return (0);
}

int		key_smashed(int keycode, t_app *app)
{
	if (keycode == 0 || keycode == 1 || \
	keycode == 2 || keycode == 13)
		app->controller.mv = keycode;
	if (keycode == 123 || keycode == 124)
		app->controller.rt = keycode;
	if (keycode == 53)
	{
		mlx_destroy_image(app->mlx_ptr, app->screen.img_ptr);
		mlx_destroy_window(app->mlx_ptr, app->mlx_win);
		exit(0);
	}
	if (keycode == 46)
	{
		app->controller.map = (app->controller.map + 1) % 2;
		update_screen(app);
		update_window(app);
	}
	if (keycode == 11)
	{
		app->controller.sky = (app->controller.sky + 1) % 2;
		update_screen(app);
		update_window(app);
	}
	return (0);
}

int		key_blessed(int keycode, t_app *app)
{
	if (keycode == 0 || keycode == 1 || \
	keycode == 2 || keycode == 13)
		app->controller.mv = -1;
	if (keycode == 123 || keycode == 124)
		app->controller.rt = -1;
	return (1);
}
