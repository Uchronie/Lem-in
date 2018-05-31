/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btaddrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 13:52:17 by lmartin-          #+#    #+#             */
/*   Updated: 2017/10/08 15:34:57 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btaddrl(t_btree **atr, t_btree *new, int (*cmpf)(void *, void *))
{
	if (!atr || !new)
		return ;
	if (!*atr)
	{
		*atr = new;
		return ;
	}
	if ((*cmpf)((*atr)->data, new->data) < 0)
	{
		if (!(*atr)->right)
			(*atr)->right = new;
		else
			ft_btaddlr(&(*atr)->right, new, cmpf);
		return ;
	}
	if (!(*atr)->left)
		(*atr)->left = new;
	else
		ft_btaddlr(&(*atr)->left, new, cmpf);
}
