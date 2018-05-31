/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:25:02 by lmartin-          #+#    #+#             */
/*   Updated: 2017/10/09 22:05:33 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	bmask(char *str)
{
	return (!(*(long*)str & 0xFF)
			|| !(*(long*)str & 0xFF00)
			|| !(*(long*)str & 0xFF0000)
			|| !(*(long*)str & 0xFF000000)
			|| !(*(long*)str & 0xFF00000000)
			|| !(*(long*)str & 0xFF0000000000)
			|| !(*(long*)str & 0xFF000000000000)
			|| !(*(long*)str & 0xFF00000000000000));
}

int			ft_strcmp(const char *s1, const char *s2)
{
	while (!bmask((char*)s1) && !bmask((char*)s2) && !(*(long*)s1 ^ *(long*)s2))
	{
		s1 += 8;
		s2 += 8;
	}
	while (*s1 && *s2 && !(*s1 ^ *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
