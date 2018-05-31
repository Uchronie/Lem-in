/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:58:28 by lmartin-          #+#    #+#             */
/*   Updated: 2017/11/03 09:14:12 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	getlen(int n, int b)
{
	size_t i;

	i = 1;
	while ((n /= b))
		i++;
	return (i);
}

char			*ft_itoa_base(int n, const int b)
{
	static char	base[] = "0123456789abcdef";
	char		*ret;
	size_t		i;

	if (b == 10)
		return (ft_itoa(n));
	if (!(ret = malloc(getlen(n, b) + 1)))
		return (NULL);
	i = 0;
	while (n)
	{
		ret[i++] = base[n % b];
		n /= b;
	}
	if (!n)
		ret[i] = 0;
	return (ft_strrev(ret));
}
