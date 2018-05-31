/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convwc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:32:34 by lmartin-          #+#    #+#             */
/*   Updated: 2017/02/03 11:46:23 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_convwc(wchar_t wchr)
{
	char	*buff;

	if (!(buff = ft_strnew(4)))
		return (NULL);
	if (wchr < (1 << 7))
		*buff = (char)wchr;
	else if (wchr < (1 << 11))
	{
		*buff = (char)((wchr >> 6) | 0xC0);
		*(buff + 1) = (char)((wchr & 0x3F) | 0x80);
	}
	else if (wchr < (1 << 16))
	{
		*buff = (char)((wchr >> 12) | 0xE0);
		*(buff + 1) = (char)(((wchr >> 6) & 0x3F) | 0x80);
		*(buff + 2) = (char)((wchr & 0x3F) | 0x80);
	}
	else if (wchr < (1 << 21))
	{
		*buff = (char)((wchr >> 18) | 0xF0);
		*(buff + 1) = (char)(((wchr >> 12) & 0x3F) | 0x80);
		*(buff + 2) = (char)(((wchr >> 6) & 0x3F) | 0x80);
		*(buff + 3) = (char)((wchr & 0x3F) | 0x80);
	}
	return (buff);
}

char	*pf_convws(wchar_t *wstr)
{
	char	*ret;

	ret = ft_strnew(1);
	ret[0] = 0;
	while (*wstr)
		ret = ft_strjoinfree(ret, pf_convwc(*(wstr++)), 3);
	return (ret);
}
