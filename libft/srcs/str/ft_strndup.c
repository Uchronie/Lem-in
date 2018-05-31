/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 12:00:28 by lmartin-          #+#    #+#             */
/*   Updated: 2017/11/03 09:13:54 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(s);
	len = (len <= n) ? len : n;
	return ((ret = malloc(len + 1)) ? ft_strncpy(ret, s, n) : NULL);
}
