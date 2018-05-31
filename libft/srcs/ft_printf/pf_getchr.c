/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_getchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 10:12:10 by lmartin-          #+#    #+#             */
/*   Updated: 2016/12/02 13:13:30 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_getchr(va_list *ap, char *flags)
{
	char	*res;
	int		ret;

	res = NULL;
	if (ft_strchr(flags, 'l'))
		res = pf_convwc(va_arg(*ap, wchar_t));
	else
	{
		res = ft_strnew(1);
		res[0] = va_arg(*ap, int);
	}
	if (!*res)
	{
		pf_applypads(&res, flags, '0');
		ret = ft_strlen(res);
		ft_strdel(&res);
		ft_strdel(&flags);
		return (ret + 1);
	}
	pf_applypads(&res, flags, 'c');
	ft_putstr(res);
	ret = ft_strlen(res);
	ft_strdel(&res);
	ft_strdel(&flags);
	return (ret);
}

char	*pf_getstr(va_list *ap, char *flags)
{
	char	*res;
	char	*tmp;
	char	*dot;
	int		dup;

	res = NULL;
	dup = 6;
	if ((dot = ft_strchr(flags, '.')))
		dup = ft_atoi(dot + 1);
	if (!(tmp = va_arg(*ap, char*)))
		res = ft_strndup("(null)", dup);
	if (tmp)
		dup = (dot) ? dup : ft_strlen(tmp);
	if (ft_strchr(flags, 'l') && !res)
	{
		tmp = pf_convws((wchar_t*)tmp);
		dup = (dot) ? dup : ft_strlen(tmp);
		res = ft_strndup(tmp, dup);
		ft_strdel(&tmp);
	}
	else if (!res)
		res = ft_strndup(tmp, dup);
	pf_applypads(&res, flags, 's');
	return (res);
}
