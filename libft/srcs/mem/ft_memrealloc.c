/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:47:24 by lmartin-          #+#    #+#             */
/*   Updated: 2016/11/12 00:26:49 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrealloc(void **ap, size_t size)
{
	void	*new;

	if (!ap)
		return (NULL);
	if (!(new = ft_memalloc(size)))
		return (NULL);
	if (*ap)
	{
		ft_memmove(new, *ap, sizeof(*ap));
		ft_memdel(ap);
	}
	return (new);
}
