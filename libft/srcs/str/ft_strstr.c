/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:59:17 by lmartin-          #+#    #+#             */
/*   Updated: 2017/10/09 09:19:26 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(const char *big, const char *little)
{
	int i;

	if (!*little)
		return ((char*)big);
	while (*big && !(i = 0))
	{
		while (little[i] == big[i])
		{
			if (little[++i] == 0)
				return ((char*)big);
		}
		big++;
	}
	return (NULL);
}
