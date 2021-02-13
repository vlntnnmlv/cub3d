/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:04:34 by rmarguri          #+#    #+#             */
/*   Updated: 2020/08/05 19:46:27 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

char	*ft_strjoin_gnl(char *a, char *b)
{
	char	*res;
	int		i;
	int		j;

	if (!a)
		return (b);
	if (!b)
		return (a);
	res = malloc(ft_strlen(a) + ft_strlen(b) + 1);
	i = 0;
	while (a[i] != '\0')
	{
		res[i] = a[i];
		i++;
	}
	j = 0;
	while (b[j] != '\0')
	{
		res[i + j] = b[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

char	*symin(char *line)
{
	int i;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (line + i);
		i++;
	}
	return (NULL);
}

int		contentcheck(char **line, char **content, int r)
{
	char *p1;
	char *p2;

	if ((p1 = symin(*content)))
	{
		*p1 = '\0';
		*line = ft_strdup(*content);
		if (!(*line))
			return (-1);
		p2 = ft_strdup(++p1);
		if (!p2)
			return (-1);
		ft_strclr(content);
		*content = p2;
		return (1);
	}
	else if (r == 0)
	{
		*line = ft_strdup(*content);
		if (!(*line))
			return (-1);
		ft_strclr(content);
		return (0);
	}
	return (1);
}

int		errorcheck(int fd, char **line, char **content, int r)
{
	if (fd < 0 || line == NULL)
		return (-1);
	else if (r == 0 && *content == NULL)
	{
		*line = ft_strdup("");
		if (!(*line))
			return (-1);
		return (0);
	}
	return (contentcheck(line, content, r));
}

int		get_next_line(int fd, char **line)
{
	static char		*content;
	char			buf[BUFFER_SIZE + 1];
	int				r;
	char			*p;

	p = NULL;
	while ((r = read(fd, buf, BUFFER_SIZE)))
	{
		if (r == -1)
			return (-1);
		buf[r] = '\0';
		if (!content)
		{
			content = ft_strnew(1);
			if (!content)
				return (-1);
		}
		if (!(p = ft_strjoin_gnl(content, buf)))
			return (-1);
		ft_strclr(&content);
		content = p;
		if (symin(content))
			break ;
	}
	return (errorcheck(fd, line, &content, r));
}
