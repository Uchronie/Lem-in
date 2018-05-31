/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:02:04 by lmartin-          #+#    #+#             */
/*   Updated: 2017/10/09 22:23:17 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (c)
	{
		if (!((*(int*)s ^ c) & 0xFF))
			return ((char*)s);
		if (!((*(int*)s ^ c << 8) & 0xFF00) && (ft_strlen(s) > 1))
			return ((char*)s + 1);
		if (!((*(int*)s ^ c << 16) & 0xFF0000) && (ft_strlen(s) > 2))
			return ((char*)s + 2);
		if (!((*(int*)s ^ c << 24) & 0xFF000000) && (ft_strlen(s) > 3))
			return ((char*)s + 3);
		if (!(*(int*)s & 0xFF) || !(*(int*)s & 0xFF00)
					|| !(*(int*)s & 0xFF0000) || !(*(int*)s & 0xFF000000))
			return (NULL);
		s += 4;
	}
	return ((char*)s + ft_strlen(s));
}
