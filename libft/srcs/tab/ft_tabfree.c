/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:37:48 by lmartin-          #+#    #+#             */
/*   Updated: 2017/11/03 09:14:43 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_tabfree(char **tab)
{
	int i;

	if (!tab || !*tab)
		return ;
	i = ft_tablen(tab);
	while (i--)
		free(tab[i]);
	free(tab);
}
