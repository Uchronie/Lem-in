/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:00:12 by lmartin-          #+#    #+#             */
/*   Updated: 2017/01/09 00:29:52 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_size;

	i = ft_strlen(dst);
	if (i >= size)
		return (size + ft_strlen(src));
	d_size = i + ft_strlen(src);
	ft_strncpy(dst + i, src, size - 1);
	return (d_size);
}
