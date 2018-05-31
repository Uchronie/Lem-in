/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:32:28 by lmartin-          #+#    #+#             */
/*   Updated: 2017/11/03 09:13:10 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	wordlen(const char *w, char c)
{
	size_t i;

	i = -1;
	while (w[++i] && w[i] != c)
		;
	return (i);
}

static int		wordcount(const char *s, char c)
{
	int i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*(s++) && *s != c)
				;
			i++;
			if (!*s)
				break ;
		}
		s++;
	}
	return (i);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**ret;
	int		i;
	int		j;

	if (!s || !(ret = malloc((wordcount(s, c) + 1) * sizeof(char*))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c && !(j = 0))
		{
			if (!(ret[i] = malloc(wordlen(s, c) + 1)))
				return (NULL);
			while (*s && *s != c)
				ret[i][j++] = *(s++);
			ret[i++][j] = 0;
			if (!*s)
				break ;
		}
		s++;
	}
	ret[i] = 0;
	return (ret);
}
