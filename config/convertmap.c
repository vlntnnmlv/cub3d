/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 17:24:32 by rmarguri          #+#    #+#             */
/*   Updated: 2020/10/29 15:02:12 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void		del(void *str, size_t size)
{
	free(str);
	str = NULL;
	size = 0;
}

int			maxstr(t_list *map)
{
	t_list				*cute;
	unsigned int		strl;

	cute = map;
	strl = ft_strlen(cute->content);
	while (cute->next != NULL)
	{
		if (ft_strlen(cute->content) > strl)
			strl = ft_strlen(cute->content);
		cute = cute->next;
	}
	if (ft_strlen(cute->content) > strl)
		strl = ft_strlen(cute->content);
	return (strl);
}

char		**convertmap(t_config *c, t_list *map)
{
	char	**new_map;
	t_list	*cur;
	int		i;
	int		l;

	l = maxstr(map->next);
	c->cols = l;
	c->rows = ft_lstlen(map->next);
	new_map = (char**)malloc((c->rows) * sizeof(char*));
	i = 0;
	cur = map->next;
	while (i < c->rows)
	{
		new_map[i] = ft_strdup_override(cur->content, l);
		cur = cur->next;
		i++;
	}
	ft_lstdel(&map, &del);
	return (new_map);
}
