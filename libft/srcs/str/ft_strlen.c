/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:25:35 by lmartin-          #+#    #+#             */
/*   Updated: 2017/10/09 21:12:28 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(char const *s)
{
	char *t_s;

	t_s = (char*)s;
	while (1)
	{
		if (!(*(int*)t_s & 0xFF))
			return (t_s - s);
		if (!(*(int*)t_s & 0xFF00))
			return (t_s - s + 1);
		if (!(*(int*)t_s & 0xFF0000))
			return (t_s - s + 2);
		if (!(*(int*)t_s & 0xFF000000))
			return (t_s - s + 3);
		t_s += 4;
	}
}
