/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 04:35:41 by lmartin-          #+#    #+#             */
/*   Updated: 2017/01/22 17:50:33 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(char *fmt, ...)
{
	int		ret;
	int		*ptr;
	va_list	ap;

	va_start(ap, fmt);
	ret = 0;
	while (*fmt)
	{
		ret += pf_readfmt(&ap, &fmt);
		if (*(fmt - 1) == 'n')
		{
			ptr = va_arg(ap, int*);
			*ptr = ret;
		}
	}
	va_end(ap);
	return (ret);
}
