/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:25:17 by lmartin-          #+#    #+#             */
/*   Updated: 2017/10/09 21:11:50 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char		*ft_strcpy(char *dest, const char *src)
{
	char *t_s;

	t_s = dest;
	while (!bmask((char*)src))
	{
		*(((long*)t_s)) = *(((long*)src));
		t_s += 8;
		src += 8;
	}
	while (*src)
		*(t_s++) = *(src++);
	*t_s = 0;
	return (dest);
}
