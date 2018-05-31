/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_readfmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:25:19 by lmartin-          #+#    #+#             */
/*   Updated: 2016/12/05 15:40:51 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_jumpflags(char **fmt)
{
	while (!ft_strchr(PF_CONV, *(++(*fmt))) && (ft_strchr(PF_FLAGS, **fmt)
	|| ft_isdigit(**fmt)) && *(*fmt))
		;
}

static char	*pf_getret(char *beg, char *flags, va_list *ap)
{
	char *ret;

	ret = NULL;
	ret = (ft_tolower(*beg) == 'd' || *beg == 'i') ? pf_getint(ap, flags) : ret;
	ret = (ft_tolower(*beg) == 'o') ? pf_getoct(ap, flags) : ret;
	ret = (ft_tolower(*beg) == 'x') ? pf_gethex(ap, flags, *beg) : ret;
	ret = (ft_tolower(*beg) == 'b') ? pf_getbin(ap, flags) : ret;
	ret = (ft_tolower(*beg) == 'u') ? pf_getuint(ap, flags) : ret;
	ret = (ft_tolower(*beg) == 's') ? pf_getstr(ap, flags) : ret;
	ret = (*beg == 'p') ? pf_getptr(ap, flags) : ret;
	ret = (!*beg) ? ft_strdup("") : ret;
	ret = (*beg == '%') ? ft_strdup("%") : ret;
	ret = (*beg == 'n') ? ft_strdup("") : ret;
	if (*beg == '%')
		pf_applypads(&ret, flags, '%');
	ft_strdel(&flags);
	return (ret);
}

char		*pf_parseflags(char *beg, va_list *ap)
{
	char	*ret;
	int		i;

	i = 0;
	beg++;
	while (beg[i] && !ft_strchr(PF_CONV, beg[i]))
	{
		if (!ft_strchr(PF_FLAGS, beg[i]) && !ft_isdigit(beg[i]))
			return ((char *)1);
		i++;
	}
	if (ft_strnstr(beg, "*", i))
		return (pf_wildprec(beg, i, ap));
	if (!(ret = ft_strndup(beg, i)))
		return (NULL);
	if (ft_isupper(beg[i]) && beg[i] != 'X')
		if (!(ret = ft_strjoinfree(ret, "l", 1)))
			return (NULL);
	return (ret);
}

int			pf_convert(va_list *ap, char *beg)
{
	char	*flags;
	char	*ret;
	int		len;

	if (!(flags = pf_parseflags(beg, ap)))
		return (-1);
	if ((int)flags == 1)
		return (0);
	if (!*(beg + 1))
		return (0);
	beg++;
	while (!ft_strchr(PF_CONV, *beg))
		beg++;
	if (ft_isupper(*beg) && *beg != 'X')
		flags = ft_strjoinfree(flags, "l", 1);
	if (ft_tolower(*beg) == 'c')
		return (pf_getchr(ap, flags));
	if (!(ret = pf_getret(beg, flags, ap)))
		return (-1);
	ft_putstr(ret);
	len = ft_strlen(ret);
	ft_strdel(&ret);
	return (len);
}

int			pf_readfmt(va_list *ap, char **fmt)
{
	int		len;

	if (!fmt || !*fmt)
		return (-1);
	if (!**fmt)
		return (0);
	if ((len = pf_printfmt(fmt)))
		return (len);
	len = pf_convert(ap, *fmt);
	pf_jumpflags(fmt);
	*fmt += (**fmt && ft_strchr(PF_CONV, **fmt)) ? 1 : 0;
	return (len);
}
