/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:38:10 by rmarguri          #+#    #+#             */
/*   Updated: 2020/10/29 15:02:58 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	main_loop(t_app *app)
{
	update_screen(app);
	update_window(app);
	mlx_hook(app->mlx_win, 2, 0, &key_smashed, app);
	mlx_hook(app->mlx_win, 3, 0, &key_blessed, app);
	mlx_loop_hook(app->mlx_ptr, &controller, app);
	mlx_hook(app->mlx_win, 17, 0, &close_window_cross, app);
	mlx_loop(app->mlx_ptr);
}

void	forge(t_app *app, int ac, char **av)
{
	if (ac >= 3 && !(ft_strncmp("--save", av[2], 6)))
		app->controller.save = 1;
	if (setup(app, av[1]))
		exit(1);
}

int		main(int ac, char **av)
{
	t_app		app;

	app.controller.save = 0;
	if (ac >= 2)
	{
		if (check_file_ext(av[1], "cub"))
		{
			forge(&app, ac, av);
			if (app.controller.save)
			{
				update_screen(&app);
				write_file(&app);
				exit(0);
			}
			main_loop(&app);
		}
		else
		{
			ft_putstr_fd("Error\nWrong file name format.\n", 1);
			exit(1);
		}
	}
	else
		ft_putstr_fd("Error\nNo map provided.\n", 1);
	return (0);
}
