/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 01:20:06 by lmartin-          #+#    #+#             */
/*   Updated: 2017/10/25 15:52:58 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi_base(const char *s, const int b)
{
	static char	base[] = "0123456789abcdef";
	int			ret;
	int			i;
	int			j;

	if (b == 10)
		return (ft_atoi(s));
	if (2 > b || b > 16)
		return (0);
	ret = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t' || *s == '\v'
			|| *s == '\f' || *s == '\r')
		s++;
	j = ft_strlen(s) - 1;
	while (*s && !(i = 0))
	{
		while (base[i] && base[i] != *s && ft_toupper(base[i]) != *s)
			if (i++ > b - 1)
				return (ret);
		ret += (i * ft_pow(b, j--));
		s++;
	}
	return (ret);
}
