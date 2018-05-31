/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 11:34:30 by lmartin-          #+#    #+#             */
/*   Updated: 2017/11/03 09:14:36 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_tabcpy(char **env)
{
	char	**ret;
	int		size;

	size = ft_tablen(env);
	if (!(ret = malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	ret[size] = NULL;
	while (size--)
	{
		if (!(ret[size] = ft_strdup(env[size])))
			return (NULL);
	}
	return (ret);
}
