/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 02:10:50 by lmartin-          #+#    #+#             */
/*   Updated: 2016/11/18 16:27:22 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree_elem(t_list **lst)
{
	if (!lst)
		return ;
	ft_memdel(&((*lst)->content));
	ft_memdel((void**)lst);
}
