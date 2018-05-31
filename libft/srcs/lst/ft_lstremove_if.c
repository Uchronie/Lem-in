/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_if.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:11:52 by lmartin-          #+#    #+#             */
/*   Updated: 2016/11/16 18:27:02 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremove_if(t_list **lst, int (*f)(void*), int value)
{
	t_list *tmp;
	t_list *tmp2;

	if (!lst || !*lst || !f)
		return ;
	while (*lst && f((*lst)->content) == value)
	{
		tmp = *lst;
		*lst = tmp->next;
		ft_memdel((void**)&tmp);
	}
	if (!(tmp = *lst))
		return ;
	while (tmp->next)
	{
		if (f(tmp->next->content) != value)
		{
			tmp2 = tmp->next;
			tmp->next = tmp2->next;
			ft_memdel((void**)&tmp2);
			continue ;
		}
		tmp = tmp->next;
	}
}
