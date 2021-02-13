/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 17:49:36 by rmarguri          #+#    #+#             */
/*   Updated: 2020/10/19 13:36:34 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int		map_t(float x, float m1, int m2)
{
	float	tmp;

	tmp = x / (float)m1;
	tmp = (tmp * (float)m2);
	return ((int)tmp % m2);
}

float	ang(t_fpoint v)
{
	float angle;
	float degrees;

	angle = atan2(v.y, v.x);
	degrees = 180 * angle / 3.14;
	return (degrees + 180);
}
