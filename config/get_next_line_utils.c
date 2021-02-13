/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:04:38 by rmarguri          #+#    #+#             */
/*   Updated: 2020/08/05 19:46:28 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

char	*ft_strnew(size_t size)
{
	void	*fresh_mem;

	if (size == ((size_t)-1))
		return (NULL);
	if (!(fresh_mem = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_memset(fresh_mem, '\0', size + 1);
	return (fresh_mem);
}

void	ft_strclr(char **s)
{
	if (s && *s)
	{
		free(*s);
		*s = NULL;
	}
}
