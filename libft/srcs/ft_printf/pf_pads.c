/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_pads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:53:20 by lmartin-          #+#    #+#             */
/*   Updated: 2016/12/16 18:27:29 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_iszflag(char *flags)
{
	char *zero;
	char *beg;

	beg = flags;
	while (*flags && (zero = ft_strchr(flags, '0')))
	{
		if (!ft_isdigit(*(zero - 1)) || zero == beg)
			return (1);
		flags++;
	}
	return (0);
}

void		pf_xpad(char **str, char *flags, int prc)
{
	char	*tmp;
	int		min;

	min = (ft_strchr(flags, '#')) ? 2 : 0;
	if (ft_strchr(flags, '-'))
		pf_getrpad(str, prc - min, ' ');
	if (pf_iszflag(flags) && !ft_strchr(flags, '.'))
		pf_getlpad(str, prc - min, '0');
	if (ft_strchr(flags, '#') && !pf_isnull(*str))
		*str = ft_strjoinfree("0x", *str, 2);
	if ((tmp = ft_strchr(flags, '.')) && (ft_strlen(*str) == 1 && **str == '0'))
	{
		tmp = ft_strndup(*str, ft_atoi(tmp + 1));
		ft_strdel(str);
		*str = tmp;
	}
	if (ft_strchr(flags, '-'))
		pf_getrpad(str, prc, ' ');
	pf_getlpad(str, prc, ' ');
}

void		pf_opad(char **str, char *flags, int prc)
{
	char	*tmp;
	int		min;

	min = (ft_strchr(flags, '#')) ? 1 : 0;
	if (ft_strchr(flags, '-'))
		pf_getrpad(str, prc - min, ' ');
	if (pf_iszflag(flags) && !ft_strchr(flags, '.'))
		pf_getlpad(str, prc - min, '0');
	if ((tmp = ft_strchr(flags, '.')) && (ft_strlen(*str) == 1 && **str == '0'))
	{
		tmp = ft_strndup(*str, ft_atoi(tmp + 1));
		ft_strdel(str);
		*str = tmp;
	}
	if (ft_strchr(flags, '#') && !(ft_strlen(*str) == 1 && **str == '0'))
		*str = ft_strjoinfree("0", *str, 2);
	if (ft_strchr(flags, '-'))
		pf_getrpad(str, prc, ' ');
	pf_getlpad(str, prc, ' ');
}

void		pf_ipad(char **str, char *flags, int prc)
{
	char	*tmp;
	int		min;

	min = (ft_strchr(flags, '+') || ft_strchr(flags, ' ')) ? 1 : 0;
	if (pf_iszflag(flags) && !ft_strchr(flags, '.') && !ft_strchr(flags, '-'))
		pf_getlpad(str, prc - min - (**str == '-' && !min), '0');
	if ((tmp = ft_strchr(flags, '.')) && (ft_strlen(*str) == 1 && **str == '0'))
	{
		tmp = ft_strndup(*str, ft_atoi(tmp + 1));
		ft_strdel(str);
		*str = tmp;
	}
	if (ft_strchr(flags, '+') && **str != '-')
		*str = ft_strjoinfree("+", *str, 2);
	else if (ft_strchr(flags, ' ') && **str != '-')
		*str = ft_strjoinfree(" ", *str, 2);
	if (ft_strchr(flags, '-'))
		pf_getrpad(str, prc, ' ');
	pf_getlpad(str, prc, ' ');
}

void		pf_zpad(char **str, char *flags, int prc)
{
	char *dot;

	prc--;
	if ((dot = ft_strchr(flags, '.'))
	&& (ft_strchr(flags, ' ') || ft_strchr(flags, '-')))
	{
		pf_getlpad(str, ft_atoi(dot + 1) - 1, '0');
		if (ft_strchr(flags, '-'))
			ft_putstr(*str);
	}
	if (ft_strchr(flags, '-'))
	{
		pf_getrpad(str, prc, ' ');
		ft_putchar(0);
		ft_putstr(*str);
	}
	else
	{
		if (pf_iszflag(flags))
			pf_getlpad(str, prc, '0');
		pf_getlpad(str, prc, ' ');
		ft_putstr(*str);
		ft_putchar(0);
	}
}
