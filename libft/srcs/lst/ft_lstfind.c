/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:22:25 by lmartin-          #+#    #+#             */
/*   Updated: 2016/11/16 15:01:51 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *lst, int (*f)(void*), int value)
{
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		if (f(lst->content) == value)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
