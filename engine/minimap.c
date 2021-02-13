/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 18:46:51 by rmarguri          #+#    #+#             */
/*   Updated: 2020/10/19 17:42:01 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int		good_color(float p, int c)
{
	int color;
	int r;
	int g;
	int b;

	r = get_r(c) > 125 ? (int)(255 * (1 - p)) : (int)(255 * p);
	g = get_g(c) > 125 ? (int)(255 * (1 - p)) : (int)(255 * p);
	b = get_b(c) > 125 ? (int)(255 * (1 - p)) : (int)(255 * p);
	color = get_trgb(0, r, g, b);
	return (color);
}

int		paint_minimap(t_app *app, t_point where, t_point there)
{
	if ((int)(where.x / MINISQUARE) == (int)(app->camera.p.x) && \
		(int)(where.y / MINISQUARE) == (int)(app->camera.p.y))
		paint_pixel(&app->screen, there, good_color(1, app->config.c));
	else if (app->config.map[(int)(where.y / MINISQUARE)]\
	[(int)(where.x / MINISQUARE)] == '1')
		paint_pixel(&app->screen, there, good_color(0.75, app->config.c));
	else if (app->config.map[(int)(where.y / MINISQUARE)]\
	[(int)(where.x / MINISQUARE)] == '2')
		paint_pixel(&app->screen, there, good_color(0.25, app->config.c));
	return (0);
}

void	draw_minimap(t_app *app)
{
	t_point	where;
	t_point	there;

	where.y = 0;
	while (where.y < MINISQUARE * (app->config.rows + 0))
	{
		where.x = 0;
		while (where.x < MINISQUARE * (app->config.cols + 0))
		{
			there.x = where.x + MINISQUARE;
			there.y = where.y + MINISQUARE;
			paint_minimap(app, where, there);
			where.x += 1;
		}
		where.y += 1;
	}
}
