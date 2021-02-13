/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:05:21 by rmarguri          #+#    #+#             */
/*   Updated: 2020/10/19 17:43:02 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manager.h"

int		close_window_cross(t_app *app)
{
	mlx_destroy_window(app->mlx_ptr, app->mlx_win);
	exit(0);
	return (0);
}
