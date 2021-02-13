/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:28:56 by rmarguri          #+#    #+#             */
/*   Updated: 2020/10/29 17:26:09 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "types.h"

t_image	null_image(void)
{
	t_image img;

	img.img_ptr = NULL;
	img.img_data = NULL;
	return (img);
}

int		config_init(t_config *config)
{
	config->w = 0;
	config->h = 0;
	config->textures = (t_image*)malloc(sizeof(t_image) * 5);
	config->textures[0] = null_image();
	config->textures[1] = null_image();
	config->textures[2] = null_image();
	config->textures[3] = null_image();
	config->textures[4] = null_image();
	config->f = -1;
	config->c = -1;
	config->map = NULL;
	config->rows = 0;
	config->cols = 0;
	config->n_sprites = 0;
	config->sprites = NULL;
	return (0);
}

int		app_init(t_app *app)
{
	app->skybox = app->config.textures[0];
	app->camera.fov = 0.66;
	app->controller.mv = -1;
	app->controller.rt = -1;
	app->controller.map = 0;
	app->controller.sky = 0;
	app->save_path = "Screenshot.bmp";
	app->screen.img_ptr = mlx_new_image(app->mlx_ptr, \
	app->config.w, app->config.h);
	app->screen.w = app->config.w;
	app->screen.h = app->config.h;
	app->screen.img_data = mlx_get_data_addr(app->screen.img_ptr, \
	&app->screen.bpp, &app->screen.line, &app->screen.endian);
	if (!app->controller.save)
		app->mlx_win = mlx_new_window(app->mlx_ptr, \
		app->config.w, app->config.h, "cub3D");
	return (0);
}

int		setup(t_app *app, char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\nCannot open file.\n", 1));
	app->mlx_ptr = mlx_init();
	mlx_get_screen_size(app->mlx_ptr, &app->stdw, &app->stdh);
	config_init(&app->config);
	if (do_config(fd, app))
		return (1);
	close(fd);
	app_init(app);
	return (0);
}

int		check_file_ext(char *file, char *ext)
{
	char *eext;

	eext = ft_strrchr(file, '.');
	if (!eext)
		return (0);
	return (ft_strncmp(eext + 1, ext, ft_strlen(ext)) == 0 ? 1 : 0);
}
