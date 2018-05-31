/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:59:17 by lmartin-          #+#    #+#             */
/*   Updated: 2017/10/09 09:17:26 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int i;
	int j;

	if (!*little)
		return ((char*)big);
	j = -1;
	while (*big && !(i = 0) && ++j < (int)len)
	{
		while (little[i] == big[i])
		{
			if (little[++i] == 0 && (unsigned)(i + j - 1) < len)
				return ((char*)big);
		}
		big++;
	}
	return (NULL);
}
