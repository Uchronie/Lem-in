/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btdensity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 14:50:52 by lmartin-          #+#    #+#             */
/*   Updated: 2017/10/08 14:52:39 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_btdensity(t_btree *root)
{
	if (!root)
		return (0);
	return (ft_btdensity(root->left) + ft_btdensity(root->right) + 1);
}
