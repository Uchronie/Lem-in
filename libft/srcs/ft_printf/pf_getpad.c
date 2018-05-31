/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_getpad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 15:16:11 by lmartin-          #+#    #+#             */
/*   Updated: 2016/12/16 18:31:09 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_isnull(char *str)
{
	while (*str == ' ' || *str == '0')
		str++;
	if (!*str)
		return (1);
	return (0);
}

int			pf_getprc(char *flags)
{
	while (*flags && *flags != '.')
	{
		if (ft_isdigit(*flags) && *flags != '0')
			return (ft_atoi(flags));
		flags++;
	}
	return (0);
}

void		pf_getlpad(char **str, int prc, char pad)
{
	int		i;
	int		sign;
	char	*buff;

	sign = (**str == '-' && pad == '0') ? 1 : 0;
	if (sign)
		ft_strcpy(*str, (*str) + 1);
	i = prc - ft_strlen(*str);
	if (i < 0)
		i = 0;
	if (!(buff = ft_strnew(i)))
	{
		ft_strdel(str);
		return ;
	}
	buff[i] = 0;
	while (i)
		buff[--i] = pad;
	*str = ft_strjoinfree(buff, *str, 3);
	if (sign)
		*str = ft_strjoinfree("-", *str, 2);
}

void		pf_getrpad(char **str, int prc, char pad)
{
	int		i;
	char	*buff;

	i = prc - ft_strlen(*str);
	if (i <= 0)
		return ;
	if (!(buff = ft_strnew(i)))
	{
		ft_strdel(str);
		return ;
	}
	buff[i] = 0;
	while (i)
		buff[--i] = pad;
	*str = ft_strjoinfree(*str, buff, 3);
}

void		pf_applypads(char **str, char *flags, char cnv)
{
	int		prc;

	prc = pf_getprc(flags);
	if (cnv == 'x')
		pf_xpad(str, flags, prc);
	else if (cnv == 'o')
		pf_opad(str, flags, prc);
	else if (cnv == 'd' || cnv == 'u')
		pf_ipad(str, flags, prc);
	else if (cnv == '0')
		pf_zpad(str, flags, prc);
	else
	{
		if (ft_strchr(flags, '-'))
			pf_getrpad(str, prc, ' ');
		if (pf_iszflag(flags))
			pf_getlpad(str, prc, '0');
		pf_getlpad(str, prc, ' ');
	}
}
