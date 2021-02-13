/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:44:28 by rmarguri          #+#    #+#             */
/*   Updated: 2020/10/12 17:07:21 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

unsigned int		get_color(t_image tex, int x, int y)
{
	unsigned int trgb;

	trgb = (tex.img_data[tex.line * y + 4 * x] + \
	tex.img_data[tex.line * y + 4 * x + 1] * 256 + \
	tex.img_data[tex.line * y + 4 * x + 2] * 256 * 256 + \
	tex.img_data[tex.line * y + 4 * x + 3] * 256 * 256 * 256);
	return (trgb);
}

int					darken(int color, float perp)
{
	int		r;
	int		g;
	int		b;
	float	p;

	r = get_r(color);
	g = get_g(color);
	b = get_b(color);
	if (perp < SMLD)
		p = 1;
	else if (perp > BIGD)
		p = 0.1;
	else
		p = 1 - 0.9 * (perp - SMLD) / (BIGD - SMLD);
	return (get_trgb(get_t(color) * p, r * p, g * p, b * p));
}

void				paint_pixel(t_image *image, \
t_point where, unsigned int color)
{
	image->img_data[where.y * image->line + where.x * 4] = \
	get_b(color);
	image->img_data[where.y * image->line + where.x * 4 + 1] = \
	get_g(color);
	image->img_data[where.y * image->line + where.x * 4 + 2] = \
	get_r(color);
	image->img_data[where.y * image->line + where.x * 4 + 3] = \
	get_t(color);
}
