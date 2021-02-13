/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 16:48:35 by rmarguri          #+#    #+#             */
/*   Updated: 2020/10/28 16:16:13 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx_mms/mlx.h"
# include <stdlib.h>
# include <math.h>
# include "types.h"
# include "libft/libft.h"
# include "engine/engine.h"
# include "config/config.h"
# include "manager/manager.h"
# include "controls/controls.h"
# include "bmp/bmp.h"

t_image		null_image(void);
int			config_init(t_config *config);
int			app_init(t_app *app);
int			setup(t_app *app, char *file);
int			check_file_ext(char *file, char *ext);
void		peepeepoopoo(t_app app);

#endif
