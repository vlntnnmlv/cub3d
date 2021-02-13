/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 16:49:53 by rmarguri          #+#    #+#             */
/*   Updated: 2020/10/09 17:07:19 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int		get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int		get_r(int trgb)
{
	return (trgb & (0xFF << 16)) / (256 * 256);
}

int		get_g(int trgb)
{
	return (trgb & (0xFF << 8)) / 256;
}

int		get_b(int trgb)
{
	return (trgb & (0xFF << 0));
}

int		get_trgb(int t, int r, int g, int b)
{
	return ((t << 24 | r << 16 | g << 8 | b));
}
