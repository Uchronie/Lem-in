/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_wildcard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 02:51:46 by lmartin-          #+#    #+#             */
/*   Updated: 2016/12/04 22:10:45 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_wildprec(char *beg, int len, va_list *ap)
{
	char	*ret;
	char	*next_card;

	ret = ft_strnew(0);
	next_card = beg;
	while ((next_card = ft_strnstr(next_card, "*", len)))
	{
		ret = ft_strjoinfree(ret, ft_strndup(beg, next_card - beg), 3);
		ret = ft_strjoinfree(ret, ft_itoa(va_arg(*ap, int)), 3);
		len -= next_card - beg;
		beg = next_card++;
	}
	ret = ft_strjoinfree(ret, ft_strndup(++beg, len), 3);
	return (ret);
}
