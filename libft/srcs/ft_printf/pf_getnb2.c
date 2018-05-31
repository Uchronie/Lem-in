/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_getnb2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:31:54 by lmartin-          #+#    #+#             */
/*   Updated: 2016/12/03 17:36:01 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*pf_getbin(va_list *ap, char *flags)
{
	char *res;
	char *dot;

	res = NULL;
	if (ft_strchr(flags, 'j'))
		res = pf_conv_ui(va_arg(*ap, uintmax_t), 2);
	else if (ft_strstr(flags, "ll"))
		res = pf_conv_ui((uintmax_t)va_arg(*ap, unsigned long long int), 2);
	else if (ft_strchr(flags, 'l') || ft_strchr(flags, 'z'))
		res = pf_conv_ui((uintmax_t)va_arg(*ap, size_t), 2);
	else if (ft_strstr(flags, "hh"))
		res = pf_conv_ui((uintmax_t)((unsigned char)va_arg(*ap, unsigned)), 2);
	else if (ft_strchr(flags, 'h'))
		res = pf_conv_ui((uintmax_t)
			((unsigned short)va_arg(*ap, unsigned)), 2);
	else
		res = pf_conv_ui((uintmax_t)va_arg(*ap, unsigned), 2);
	if ((dot = ft_strchr(flags, '.')))
		pf_getlpad(&res, ft_atoi(dot + 1), '0');
	pf_applypads(&res, flags, 'b');
	return (res);
}
