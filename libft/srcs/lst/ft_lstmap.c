/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:21:26 by lmartin-          #+#    #+#             */
/*   Updated: 2016/12/09 02:38:50 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ret;
	t_list *tmp;

	if (!f)
		return (NULL);
	ret = NULL;
	while (lst)
	{
		tmp = f(lst);
		ft_lstappend(&ret, tmp);
		lst = lst->next;
	}
	return (ret);
}
