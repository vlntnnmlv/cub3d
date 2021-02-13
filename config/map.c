/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:10:37 by rmarguri          #+#    #+#             */
/*   Updated: 2020/10/19 15:09:27 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	set_p_dir(char l, t_app *app)
{
	if (l == 'N')
	{
		app->camera.p_dir.x = 0;
		app->camera.p_dir.y = -1;
	}
	if (l == 'S')
	{
		app->camera.p_dir.x = 0;
		app->camera.p_dir.y = 1;
	}
	if (l == 'W')
	{
		app->camera.p_dir.x = -1;
		app->camera.p_dir.y = 0;
	}
	if (l == 'E')
	{
		app->camera.p_dir.x = 1;
		app->camera.p_dir.y = 0;
	}
}

int		checkplayer(t_app *app, int counter, char *line)
{
	int i;
	int p;

	i = 0;
	p = 0;
	while (line[i] != '\0')
	{
		if ((line[i] == 'N' || line[i] == 'S' || \
		line[i] == 'W' || line[i] == 'E') && p)
			return (2);
		if (line[i] == 'N' || line[i] == 'S' || \
		line[i] == 'W' || line[i] == 'E')
		{
			p = 1;
			app->camera.p.x = i + 0.5;
			app->camera.p.y = counter - 0.5;
			set_p_dir(line[i], app);
		}
		if (line[i] == '2')
			app->config.n_sprites += 1;
		i++;
	}
	return (p);
}

int		walkable(char c)
{
	if (c == '0' || c == '2' || \
	c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int		surrable(char *line, int i)
{
	char c;

	if ((unsigned int)i > ft_strlen(line) - 1)
		c = ' ';
	else
		c = line[i];
	if (c == '0' || c == '2' || c == '1' || \
	c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int		is_closed(char *line, char *prevline)
{
	int i;

	i = 1;
	if (walkable(line[0]))
		return (ft_putstr_fd("Error\nMap isn't closed.\n", 1));
	if (walkable(line[ft_strlen(line) - 1]))
		return (ft_putstr_fd("Error\nMap isn't closed.\n", 1));
	while (line[i + 1] != '\0')
	{
		if (walkable(line[i]))
		{
			if (!surrable(line, i - 1))
				return (ft_putstr_fd("Error\nMap isn't closed.\n", 1));
			if (!surrable(line, i + 1))
				return (ft_putstr_fd("Error\nMap isn't closed.\n", 1));
			if (!surrable(prevline, i - 1))
				return (ft_putstr_fd("Error\nMap isn't closed.\n", 1));
			if (!surrable(prevline, i))
				return (ft_putstr_fd("Error\nMap isn't closed.\n", 1));
			if (!surrable(prevline, i + 1))
				return (ft_putstr_fd("Error\nMap isn't closed.\n", 1));
		}
		i++;
	}
	return (0);
}
