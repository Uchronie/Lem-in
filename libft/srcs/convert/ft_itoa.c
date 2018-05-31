/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 02:00:34 by lmartin-          #+#    #+#             */
/*   Updated: 2017/11/03 09:14:07 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	get_size(int n)
{
	size_t i;

	if (!n)
		return (1);
	i = 0;
	while ((n /= 10))
		i++;
	return (i + 1);
}

char			*ft_itoa(int n)
{
	char				*ret;
	unsigned int		nb;
	int					i;
	size_t				size;

	i = 0;
	nb = (n < 0) ? -n : n;
	size = (n < 0) ? get_size(nb) + 1 : get_size(nb);
	if (!(ret = malloc(size + 1)))
		return (NULL);
	while (nb)
	{
		ret[i++] = (nb % 10) + 48;
		nb /= 10;
	}
	if (!n)
		ret[i] = 48;
	if (n < 0)
		ret[i] = '-';
	return (ft_strrev(ret));
}
