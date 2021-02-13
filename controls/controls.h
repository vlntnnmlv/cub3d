/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:03:58 by rmarguri          #+#    #+#             */
/*   Updated: 2020/10/20 16:56:08 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

# define ROTSPEED 5
# define MOVSPEED 0.12

# include "../cub3d.h"
# include "../types.h"
# include "../engine/engine.h"

int		move(int keycode, t_app *app);
int		rotate(int keycode, t_app *app);
int		update_screen(t_app *app);
int		update_window(t_app *app);

int		key_smashed(int keycode, t_app *app);
int		key_blessed(int keycode, t_app *app);
int		controller(t_app *app);

#endif
