/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 17:45:12 by lmartin-          #+#    #+#             */
/*   Updated: 2017/08/09 18:04:16 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcpy(t_list *lst)
{
	t_list *ret;
	t_list *tmp;

	if (!lst)
		return (NULL);
	ret = NULL;
	while (lst)
	{
		if (!(tmp = ft_lstnew(lst->content, lst->content_size)))
			return (NULL);
		ft_lstappend(&ret, tmp);
		lst = lst->next;
	}
	return (ret);
}
