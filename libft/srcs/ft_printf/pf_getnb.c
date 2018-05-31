/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_getnb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 23:38:04 by lmartin-          #+#    #+#             */
/*   Updated: 2016/12/03 17:47:07 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_toupper(char *s)
{
	while (*s)
	{
		*s = ft_toupper(*s);
		s++;
	}
}

char		*pf_getint(va_list *ap, char *flags)
{
	char	*res;
	char	*dot;

	res = NULL;
	if (ft_strchr(flags, 'j'))
		res = pf_conv_i(va_arg(*ap, intmax_t), 10);
	else if (ft_strstr(flags, "ll") || ft_strchr(flags, 'z'))
		res = pf_conv_i((intmax_t)va_arg(*ap, long long int), 10);
	else if (ft_strchr(flags, 'l'))
		res = pf_conv_i((intmax_t)va_arg(*ap, long int), 10);
	else if (ft_strstr(flags, "hh"))
		res = pf_conv_i((intmax_t)((char)va_arg(*ap, int)), 10);
	else if (ft_strchr(flags, 'h'))
		res = pf_conv_i((intmax_t)((short)va_arg(*ap, int)), 10);
	else
		res = pf_conv_i((intmax_t)va_arg(*ap, int), 10);
	if ((dot = ft_strchr(flags, '.')))
		pf_getlpad(&res, ft_atoi(dot + 1), '0');
	pf_applypads(&res, flags, 'd');
	return (res);
}

char		*pf_getoct(va_list *ap, char *flags)
{
	char *res;
	char *dot;

	res = NULL;
	if (ft_strchr(flags, 'j'))
		res = pf_conv_ui(va_arg(*ap, uintmax_t), 8);
	else if (ft_strstr(flags, "ll"))
		res = pf_conv_ui((uintmax_t)va_arg(*ap, unsigned long long int), 8);
	else if (ft_strchr(flags, 'l') || ft_strchr(flags, 'z'))
		res = pf_conv_ui((uintmax_t)va_arg(*ap, size_t), 8);
	else if (ft_strstr(flags, "hh"))
		res = pf_conv_ui((uintmax_t)((unsigned char)va_arg(*ap, unsigned)), 8);
	else if (ft_strchr(flags, 'h'))
		res = pf_conv_ui((uintmax_t)
			((unsigned short)va_arg(*ap, unsigned)), 8);
	else
		res = pf_conv_ui((uintmax_t)va_arg(*ap, unsigned), 8);
	if ((dot = ft_strchr(flags, '.')))
		pf_getlpad(&res, ft_atoi(dot + 1), '0');
	pf_applypads(&res, flags, 'o');
	return (res);
}

char		*pf_gethex(va_list *ap, char *flags, char cnv)
{
	char *res;
	char *dot;

	res = NULL;
	if (ft_strchr(flags, 'j'))
		res = pf_conv_ui(va_arg(*ap, uintmax_t), 16);
	else if (ft_strstr(flags, "ll"))
		res = pf_conv_ui((uintmax_t)va_arg(*ap, unsigned long long int), 16);
	else if (ft_strchr(flags, 'l') || ft_strchr(flags, 'z'))
		res = pf_conv_ui((uintmax_t)va_arg(*ap, size_t), 16);
	else if (ft_strstr(flags, "hh"))
		res = pf_conv_ui((uintmax_t)((unsigned char)va_arg(*ap, unsigned)), 16);
	else if (ft_strchr(flags, 'h'))
		res = pf_conv_ui((uintmax_t)
			((unsigned short)va_arg(*ap, unsigned)), 16);
	else
		res = pf_conv_ui((uintmax_t)va_arg(*ap, unsigned), 16);
	if ((dot = ft_strchr(flags, '.')))
		pf_getlpad(&res, ft_atoi(dot + 1), '0');
	pf_applypads(&res, flags, 'x');
	ft_isupper(cnv) ? pf_toupper(res) : cnv;
	return (res);
}

char		*pf_getuint(va_list *ap, char *flags)
{
	char *res;
	char *dot;

	res = NULL;
	if (ft_strchr(flags, 'j'))
		res = pf_conv_ui(va_arg(*ap, uintmax_t), 10);
	else if (ft_strstr(flags, "ll"))
		res = pf_conv_ui((uintmax_t)va_arg(*ap, unsigned long long int), 10);
	else if (ft_strchr(flags, 'l') || ft_strchr(flags, 'z'))
		res = pf_conv_ui((uintmax_t)va_arg(*ap, size_t), 10);
	else if (ft_strstr(flags, "hh"))
		res = pf_conv_ui((uintmax_t)((unsigned char)va_arg(*ap, unsigned)), 10);
	else if (ft_strchr(flags, 'h'))
		res = pf_conv_ui((uintmax_t)
			((unsigned short)va_arg(*ap, unsigned)), 10);
	else
		res = pf_conv_ui((uintmax_t)va_arg(*ap, unsigned), 10);
	if ((dot = ft_strchr(flags, '.')))
		pf_getlpad(&res, ft_atoi(dot + 1), '0');
	pf_applypads(&res, flags, 'x');
	return (res);
}
