/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btdepth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 14:53:31 by lmartin-          #+#    #+#             */
/*   Updated: 2017/10/08 15:34:32 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_btdepth(t_btree *root)
{
	int left;
	int right;

	if (!root)
		return (0);
	left = ft_btdepth(root->left);
	right = ft_btdepth(root->right);
	return (left ^ ((left ^ right) & -(left < right)));
}
