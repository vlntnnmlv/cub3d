/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 16:54:37 by rmarguri          #+#    #+#             */
/*   Updated: 2020/10/29 15:01:09 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int		validate_res(t_app *app, int j, char *str, int **wh)
{
	long long int donkey;

	donkey = ft_atol(str);
	if (donkey > 2147483647)
	{
		if (j == 0)
			*wh[j] = app->stdw;
		if (j == 1)
			*wh[j] = app->stdh;
	}
	else
		*wh[j] = (int)donkey;
	return (0);
}

int		parse_res(t_app *app, char *str, int *w, int *h)
{
	int		i;
	int		j;
	int		*wh[2];

	i = 0;
	j = 0;
	wh[0] = w;
	wh[1] = h;
	while ((*w == 0 || *h == 0) && j < 2)
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (!str[i])
			return (1);
		validate_res(app, j, str + i, wh);
		j++;
		while (str[i] >= '0' && str[i] <= '9' && str[i])
			i++;
		if (!str[i] && j != 2)
			return (1);
	}
	if (!onlysymsin(str + i, " \t"))
		return (1);
	return (0);
}

int		move_i(char *str, int *i, int j)
{
	int k;

	if (str[*i] < '0' || str[*i] > '9')
		return (ft_putstr_fd("Error\nWrong color line format.\n", 1));
	k = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*i += 1;
		k++;
		if (k > 3)
			return (ft_putstr_fd("Error\nWrong color line format.\n", 1));
	}
	if (j <= 2 && str[*i] != ',')
		return (ft_putstr_fd("Error\nWrong color line format.\n", 1));
	if (j <= 2)
		*i += 1;
	if (j == 3 && !onlysymsin(str + *i, " \t"))
		return (ft_putstr_fd("Error\nWrong color line format.\n", 1));
	return (0);
}

int		parse_colors(char *str, int *r, int *g, int *b)
{
	int	i;
	int j;
	int	*rgb[3];

	rgb[0] = r;
	rgb[1] = g;
	rgb[2] = b;
	i = 0;
	j = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != '\0' && j < 3)
	{
		*rgb[j] = ft_atoi(str + i);
		j++;
		if (move_i(str, &i, j))
			return (1);
	}
	return (0);
}
