/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btnode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 20:16:59 by lmartin-          #+#    #+#             */
/*   Updated: 2017/11/03 09:15:05 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_btree	*ft_btnode(void *data, size_t size)
{
	t_btree	*ret;

	if (!(ret = malloc(sizeof(t_btree))))
		return (NULL);
	ret->left = NULL;
	ret->right = NULL;
	if (!data)
	{
		ret->data = NULL;
		ret->size = 0;
		return (ret);
	}
	if (!(ret->data = malloc(size)))
		return (NULL);
	ft_memmove(ret->data, data, size);
	ret->size = size;
	return (ret);
}
