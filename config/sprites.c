/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 19:10:00 by rmarguri          #+#    #+#             */
/*   Updated: 2020/10/19 17:42:26 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int		get_sprites(t_app *app)
{
	int i;
	int j;
	int	k;

	i = 0;
	k = 0;
	app->config.sprites = (t_sprite*)malloc(sizeof(t_sprite) * \
	app->config.n_sprites);
	while (i < app->config.rows)
	{
		j = 0;
		while (app->config.map[i][j] != '\0')
		{
			if (app->config.map[i][j] == '2')
			{
				app->config.sprites[k].tex = app->config.textures[4];
				app->config.sprites[k].x = j + 0.5;
				app->config.sprites[k].y = i + 0.5;
				k++;
			}
			j++;
		}
		i++;
	}
	return (0);
}
