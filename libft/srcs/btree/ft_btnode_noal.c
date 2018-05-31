/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btnode_noal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 11:24:21 by lmartin-          #+#    #+#             */
/*   Updated: 2017/11/03 09:15:07 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_btree	*ft_btnode_noal(void *data, size_t size)
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
	ret->data = data;
	ret->size = size;
	return (ret);
}
