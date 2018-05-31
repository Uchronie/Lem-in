/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 01:06:01 by lmartin-          #+#    #+#             */
/*   Updated: 2017/06/07 19:03:02 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2, int which)
{
	char *ret;

	ret = ft_strjoin(s1, s2);
	if (which == 1 || which == 3)
		ft_strdel(&s1);
	if (which == 2 || which == 3)
		ft_strdel(&s2);
	return (ret);
}
