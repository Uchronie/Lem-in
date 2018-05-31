/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:38:59 by lmartin-          #+#    #+#             */
/*   Updated: 2017/11/11 00:23:10 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = 0;
	if (dst > src)
		ft_memcpy(dst, src, len);
	else
		while (i < len)
		{
			if (i + 8 < len)
			{
				*(long*)(dst + i) = *(long*)(src + i);
				i += 8;
			}
			if (i + 4 < len)
			{
				*(int*)(dst + i) = *(int*)(src + i);
				i += 4;
			}
			else
			{
				*(char*)(dst + i) = *(char*)(src + i);
				i++;
			}
		}
	return (dst);
}
