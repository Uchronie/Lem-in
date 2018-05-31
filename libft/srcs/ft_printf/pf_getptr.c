/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_getptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:35:26 by lmartin-          #+#    #+#             */
/*   Updated: 2017/02/03 11:45:16 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_getptr(va_list *ap, char *flags)
{
	char *res;
	char *dot;

	res = pf_conv_ui((uintmax_t)va_arg(*ap, void*), 16);
	if ((dot = ft_strchr(flags, '.')))
		pf_getlpad(&res, ft_atoi(dot + 1), '0');
	if (dot && !ft_atoi(dot + 1) && *res == '0')
	{
		ft_strdel(&res);
		res = ft_strdup("");
	}
	if (pf_iszflag(flags) && !ft_strchr(flags, '.'))
		pf_getlpad(&res, pf_getprc(flags) - 2, '0');
	if (!(res = ft_strjoinfree("0x", res, 2)))
		return (NULL);
	pf_applypads(&res, flags, 'p');
	return (res);
}
