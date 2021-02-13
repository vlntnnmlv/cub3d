/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 17:03:21 by rmarguri          #+#    #+#             */
/*   Updated: 2020/10/28 16:49:05 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int		get_res(t_app *app, char *line)
{
	int	i;

	if (line[0] == 'R' && (line[1] == ' ' || line[1] == '\t'))
	{
		i = 1;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (ft_strlen(line + i) >= 40)
			return (ft_putstr_fd("Error\nResolution string is too long.\n", 1));
		if (app->config.w != 0 || app->config.h != 0)
			return (ft_putstr_fd("Error\nResolution is being set twice.\n", 1));
		if (parse_res(app, line + i, &app->config.w, &app->config.h))
			return (ft_putstr_fd("Error\nWrong color string format.\n", 1));
		if (app->config.w <= 1 || app->config.h <= 1)
			return (ft_putstr_fd("Error\nWrong resolution values.\n", 1));
		app->config.w = app->config.w > app->stdw ? app->stdw : app->config.w;
		app->config.h = app->config.h > app->stdh ? app->stdh : app->config.h;
	}
	return (0);
}

int		is_texture(char *line)
{
	if (!ft_strncmp("NO ", line, 3) || !ft_strncmp("NO\t", line, 3))
		return (0);
	if (!ft_strncmp("SO ", line, 3) || !ft_strncmp("SO\t", line, 3))
		return (1);
	if (!ft_strncmp("WE ", line, 3) || !ft_strncmp("WE\t", line, 3))
		return (2);
	if (!ft_strncmp("EA ", line, 3) || !ft_strncmp("EA\t", line, 3))
		return (3);
	if (!ft_strncmp("S ", line, 2) || !ft_strncmp("S\t", line, 2))
		return (4);
	return (-1);
}

int		get_textures(t_app *app, char *line)
{
	int		tex_id;
	int		pad;
	int		error;
	char	*tmp;

	tex_id = is_texture(line);
	pad = tex_id == 4 ? 1 : 2;
	error = 0;
	if (tex_id >= 0 && tex_id <= 4)
	{
		if (!app->config.textures[tex_id].img_ptr)
		{
			error += fill_texture(&app->config.textures[tex_id], app, \
			tmp = ft_strtrim(line + pad, " \t"));
			if (error > 0)
				return (error);
			free(tmp);
		}
		else
			return (ft_putstr_fd("Error\nTexture is being set twice.\n", 1));
	}
	return (0);
}

int		get_colors(t_config *config, char *line)
{
	int		r;
	int		g;
	int		b;

	r = -1;
	g = -1;
	b = -1;
	if ((line[0] == 'F' || line[0] == 'C') && \
	(line[1] == ' ' || line[1] == '\t'))
	{
		if ((line[0] == 'F' && config->f != -1) || \
			(line[0] == 'C' && config->c != -1))
			return (ft_putstr_fd("Error\nColor is being set twice.\n", 1));
		if (parse_colors(line + 2, &r, &g, &b))
			return (1);
		if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
			return (ft_putstr_fd("Error\nWrong color values.\n", 1));
	}
	if (line[0] == 'F')
		config->f = (r << 16 | g << 8 | b);
	if (line[0] == 'C')
		config->c = (r << 16 | g << 8 | b);
	return (0);
}
