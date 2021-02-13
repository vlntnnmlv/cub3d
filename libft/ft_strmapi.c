/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 19:20:55 by rmarguri          #+#    #+#             */
/*   Updated: 2020/05/25 19:20:57 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strnew(size_t size)
{
	void	*fresh_mem;

	if (size == ((size_t)-1))
		return (NULL);
	if (!(fresh_mem = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_memset(fresh_mem, '\0', size + 1);
	return (fresh_mem);
}

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fresh_s;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(fresh_s = ft_strnew((size_t)ft_strlen(s))))
		return (NULL);
	while (s[i])
	{
		fresh_s[i] = f(i, (char)s[i]);
		i++;
	}
	return (fresh_s);
}
