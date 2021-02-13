/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:04:45 by rmarguri          #+#    #+#             */
/*   Updated: 2020/10/29 15:01:58 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# define BUFFER_SIZE 10
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx_mms/mlx.h"
# include "../libft/libft.h"
# include "../types.h"

int			validate_line(char *line);
int			get_res(t_app *app, char *line);
int			get_textures(t_app *app, char *line);
int			fill_texture(t_image *tex, t_app *app, char *file);
int			get_colors(t_config *config, char *line);
int			do_config(int fd, t_app *app);
int			get_next_line(int fd, char **line);
char		*symin(char *line);
void		ft_strclr(char **s);
char		*check_content(char *content, char **line);
char		*ft_strnew(size_t size);
int			get_map(t_list *map, t_app *app, char *line, int k);
int			get_sprites(t_app *app);
int			onlysymsin(char *line, char *set);
char		**convertmap(t_config *c, t_list *map);
int			is_closed(char *line, char *prevline);
int			surrable(char *line, int i);
int			walkable(char c);
int			checkplayer(t_app *app, int counter, char *line);
void		set_p_dir(char l, t_app *app);

int			parse_res(t_app *app, char *str, int *w, int *h);
int			parse_colors(char *str, int *r, int *g, int *b);

#endif
