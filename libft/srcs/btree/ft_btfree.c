/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 14:43:35 by lmartin-          #+#    #+#             */
/*   Updated: 2017/11/03 09:15:18 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_btfree(t_btree **root, int free_data)
{
	if (!*root)
		return ;
	ft_btfree(&(*root)->left, free_data);
	ft_btfree(&(*root)->right, free_data);
	if (free_data)
		free((*root)->data);
	free(*root);
	*root = NULL;
}
