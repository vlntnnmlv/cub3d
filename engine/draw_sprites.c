/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 16:30:22 by rmarguri          #+#    #+#             */
/*   Updated: 2020/10/12 17:07:42 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int			validate_sprite(t_app *app, t_sprite sprite, \
			t_point where, float *dist_b)
{
	if (sprite.transf.y > 0 && where.x > 0 && where.x < app->config.w && \
	sprite.transf.y < dist_b[where.x])
		return (1);
	return (0);
}

void		sort_sprites(t_app *app, t_sprite *sprites, t_fpoint pos)
{
	int			k;
	int			i;
	t_sprite	tmp;

	k = 1;
	while (k == 1)
	{
		k = 0;
		i = 0;
		while (i < app->config.n_sprites - 1)
		{
			if (sq_dist(sprites[i], pos) < sq_dist(sprites[i + 1], pos))
			{
				tmp = sprites[i];
				sprites[i] = sprites[i + 1];
				sprites[i + 1] = tmp;
				k = 1;
			}
			i++;
		}
	}
}

void		draw_sprite(t_app *app, t_sprite sprite, float *dist_b)
{
	t_point where;
	int		d;
	int		y;
	int		color;
	t_point	t;

	where.x = sprite.draw_s.x - 1;
	while (++where.x < sprite.draw_e.x)
	{
		t.x = (int)(256 * (where.x - (sprite.s_s_x - sprite.dim.x / 2)) * \
		sprite.tex.w / sprite.dim.x) / 256;
		if (validate_sprite(app, sprite, where, dist_b))
		{
			y = sprite.draw_s.y - 1;
			while (++y < sprite.draw_e.y)
			{
				d = y * 256 - app->config.h * 128 + sprite.dim.y * 128;
				t.y = ((d * sprite.tex.h) / sprite.dim.y) / 256;
				color = darken(get_color(sprite.tex, t.x, t.y), DIST(sprite));
				where.y = y;
				if ((color & 0x00FFFFFF) != 0)
					paint_pixel(&app->screen, where, color);
			}
		}
	}
}

void		draw_sprites(t_app *app, const t_fpoint pos, \
float *dist_b)
{
	int			i;
	t_sprite	sprite;

	sort_sprites(app, app->config.sprites, pos);
	i = 0;
	while (i < app->config.n_sprites)
	{
		sprite = app->config.sprites[i];
		set_sprite(app, &sprite, pos, i);
		draw_sprite(app, sprite, dist_b);
		i++;
	}
}
