/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:50:39 by rmarguri          #+#    #+#             */
/*   Updated: 2020/10/29 15:02:05 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int		check_config(t_config c)
{
	if (c.w != 0 && c.h != 0 && \
	c.textures[0].img_ptr != NULL && \
	c.textures[1].img_ptr != NULL && \
	c.textures[2].img_ptr != NULL && \
	c.textures[3].img_ptr != NULL && \
	c.textures[4].img_ptr != NULL && \
	c.f != -1 && c.c != -1)
		return (1);
	return (0);
}

int		get_map(t_list *map, t_app *app, char *line, int k)
{
	static int	counter;
	static int	player;
	int			error;

	counter = !counter ? 0 : counter;
	player = !player ? 0 : player;
	error = 0;
	if (!onlysymsin(line, " \t"))
		counter++;
	if (onlysymsin(line, " \t") && !counter)
		return (0);
	if (onlysymsin(line, " \t") && counter)
		return (ft_putstr_fd("Error\nEmpty line\n", 1));
	if ((counter == 1 || k == 1) && !onlysymsin(line, "1 \t"))
		return (ft_putstr_fd("Error\nMap isn't closed\n", 1));
	if (counter != 1 && k != 1)
	{
		error += is_closed(line, ft_lstlast(map));
		if ((player += checkplayer(app, counter, line)) > 1)
			return (ft_putstr_fd("Error\nMore then one player.\n", 1));
	}
	if (k == 1 && player == 0)
		return (ft_putstr_fd("Error\nNo player.\n", 1));
	ft_lst_push_back(&map, line, ft_strlen(line) + 1);
	return (error);
}

int		do_settings(int fd, t_app *app)
{
	char	*line;
	int		error;

	error = 0;
	while ((get_next_line(fd, &line) == 1) && !check_config(app->config))
	{
		error += validate_line(line);
		error += get_res(app, line);
		error += get_textures(app, line);
		error += get_colors(&app->config, line);
		if (error > 0)
			return (error);
		free(line);
	}
	if (!check_config(app->config))
		return (ft_putstr_fd("Error\nNot enough parametrs.\n", 1));
	if (!onlysymsin(line, " \t"))
		return (ft_putstr_fd("Error\nOdd information in file.\n", 1));
	free(line);
	return (error);
}

int		do_map(int fd, t_app *app)
{
	char	*line;
	int		error;
	t_list	*map;

	error = 0;
	map = ft_lstnew("<start>", 8);
	while ((get_next_line(fd, &line) == 1))
	{
		if ((error = (get_map(map, app, line, 0))))
			return (error);
		free(line);
	}
	if ((error = (get_map(map, app, line, 1))))
		return (error);
	free(line);
	app->config.map = convertmap(&app->config, map);
	get_sprites(app);
	return (error);
}

int		do_config(int fd, t_app *app)
{
	int		error;

	error = 0;
	error += do_settings(fd, app);
	if (error > 0)
		return (error);
	error += do_map(fd, app);
	return (error);
}
