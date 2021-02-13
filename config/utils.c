/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:30:55 by rmarguri          #+#    #+#             */
/*   Updated: 2020/10/29 15:01:27 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int		fill_texture(t_image *tex, t_app *app, char *file)
{
	int		fd;

	if (file)
	{
		if ((fd = open(file, O_RDONLY)) == -1)
			return (ft_putstr_fd("Error\nFailed to read texture file.\n", 1));
		else
			close(fd);
		tex->img_ptr = mlx_xpm_file_to_image(app->mlx_ptr, \
		file, &tex->w, &tex->h);
		if (tex->img_ptr == NULL)
			return (ft_putstr_fd("Error\nFailed to read texture file.\n", 1));
		tex->img_data = mlx_get_data_addr(tex->img_ptr, \
		&tex->bpp, &tex->line, &tex->endian);
		if (tex->img_data != NULL && tex->img_ptr != NULL)
			return (0);
	}
	return (ft_putstr_fd("Error\nNo file specified.\n", 1));
}

int		validate_line(char *line)
{
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "NO\t", 3) || \
		!ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "SO\t", 3) || \
		!ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "WE\t", 3) || \
		!ft_strncmp(line, "EA ", 3) || !ft_strncmp(line, "EA\t", 3) || \
		!ft_strncmp(line, "S ", 2) || !ft_strncmp(line, "S\t", 2) || \
		!ft_strncmp(line, "R ", 2) || !ft_strncmp(line, "R\t", 2) || \
		!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "F\t", 2) || \
		!ft_strncmp(line, "C ", 2) || !ft_strncmp(line, "C\t", 2) || \
		onlysymsin(line, " \t"))
		return (0);
	else
		return (ft_putstr_fd("Error\nOdd information in file.\n", 1));
}

int		onlysymsin(char *line, char *set)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!(ft_strchr(set, line[i])))
			return (0);
		i++;
	}
	return (1);
}
