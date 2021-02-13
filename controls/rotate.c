/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 16:38:55 by rmarguri          #+#    #+#             */
/*   Updated: 2020/10/19 17:42:37 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"

void	rotate_v(t_fpoint *v, float tetta, int dir)
{
	t_fpoint old;

	old = *v;
	v->x = old.x * cos(dir * tetta) - old.y * sin(dir * tetta);
	v->y = old.x * sin(dir * tetta) + old.y * cos(dir * tetta);
}

int		rotate(int keycode, t_app *app)
{
	t_fpoint p;

	p.x = app->camera.p_dir.x;
	p.y = app->camera.p_dir.y;
	if (keycode == 123)
		rotate_v(&app->camera.p_dir, DEG * ROTSPEED, -1);
	else if (keycode == 124)
		rotate_v(&app->camera.p_dir, DEG * ROTSPEED, 1);
	update_screen(app);
	update_window(app);
	return (0);
}
