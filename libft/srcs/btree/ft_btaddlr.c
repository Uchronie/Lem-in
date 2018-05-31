/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btaddlr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 11:37:05 by lmartin-          #+#    #+#             */
/*   Updated: 2017/10/08 15:35:00 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btaddlr(t_btree **atr, t_btree *new, int (*cmpf)(void *, void *))
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
		if (!(*atr)->left)
			(*atr)->left = new;
		else
			ft_btaddlr(&(*atr)->left, new, cmpf);
		return ;
	}
	if (!(*atr)->right)
		(*atr)->right = new;
	else
		ft_btaddlr(&(*atr)->right, new, cmpf);
}
