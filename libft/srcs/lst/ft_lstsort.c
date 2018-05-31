/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 20:50:01 by lmartin-          #+#    #+#             */
/*   Updated: 2016/12/20 21:45:55 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list *lst, int (*cmp)(void*, void*))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(tmp = lst))
		return ;
	while ((tmp2 = tmp->next))
	{
		if (cmp(tmp->content, tmp2->content) > 0)
		{
			ft_lstswap(tmp, tmp2);
			tmp = lst;
			continue ;
		}
		tmp = tmp->next;
	}
}
