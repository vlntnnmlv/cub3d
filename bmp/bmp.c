/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 16:38:39 by rmarguri          #+#    #+#             */
/*   Updated: 2020/10/23 17:18:28 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp.h"

int		char_set(unsigned char *s, int value)
{
	s[0] = value;
	s[1] = value >> 8;
	s[2] = value >> 16;
	s[3] = value >> 24;
	return (0);
}

int		write_header(int fd, t_app *app)
{
	int							size;
	static unsigned char		header[54] = {0, 0, 0, 0, 0, 0, 0, 0, 0,\
										0, 0, 0, 0, 0, 0, 0, 0, 0,\
										0, 0, 0, 0, 0, 0, 0, 0, 0,\
										0, 0, 0, 0, 0, 0, 0, 0, 0,\
										0, 0, 0, 0, 0, 0, 0, 0, 0,\
										0, 0, 0, 0, 0, 0, 0, 0, 0
									};

	size = 54 + app->screen.bpp / 8 * \
	(app->screen.w + app->screen.bpp % 4) * app->screen.h;
	header[0] = 'B';
	header[1] = 'M';
	char_set(header + 2, size);
	char_set(header + 10, 54);
	char_set(header + 14, 40);
	char_set(header + 18, app->screen.w);
	char_set(header + 22, app->screen.h);
	header[26] = 1;
	header[28] = app->screen.bpp;
	if ((write(fd, header, 54)) == -1)
		return (1);
	return (0);
}

int		write_colors(int fd, t_app *app)
{
	int				y;
	int				x;
	int				w;
	int				h;
	unsigned char	bgrt[4];

	w = app->screen.w;
	h = app->screen.h;
	y = h;
	while (--y >= 0)
	{
		x = -1;
		while (++x < w)
		{
			bgrt[0] = (unsigned char)get_b(get_color(app->screen, x, y));
			bgrt[1] = (unsigned char)get_g(get_color(app->screen, x, y));
			bgrt[2] = (unsigned char)get_r(get_color(app->screen, x, y));
			bgrt[3] = (unsigned char)get_t(get_color(app->screen, x, y));
			if ((write(fd, bgrt, 4)) == -1)
				return (1);
		}
	}
	return (0);
}

int		write_file(t_app *app)
{
	int					fd;

	fd = open(app->save_path, O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		ft_putstr_fd("Error\nFailed to create screenshot file.\n", 1);
	write_header(fd, app);
	write_colors(fd, app);
	close(fd);
	return (0);
}
