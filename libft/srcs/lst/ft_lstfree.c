/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 02:10:50 by lmartin-          #+#    #+#             */
/*   Updated: 2016/11/18 16:19:45 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	while ((*lst)->next)
	{
		tmp = *lst;
		*lst = tmp->next;
		ft_lstfree_elem(&tmp);
	}
	ft_lstfree_elem(lst);
}
