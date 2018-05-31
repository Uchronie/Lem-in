/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:51:26 by lmartin-          #+#    #+#             */
/*   Updated: 2016/12/02 17:54:34 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	nb_len(uintmax_t nb, int base)
{
	size_t	i;

	i = 1;
	while (nb /= base)
		i++;
	return (i);
}

char			*pf_conv_i(intmax_t nb, int base)
{
	int					i;
	char				*s;
	static char			b[] = "0123456789abcdef";
	uintmax_t			n;

	n = (nb < 0) ? -nb : nb;
	i = nb_len(n, base) + (nb < 0 && base == 10);
	if (!(s = ft_strnew(i)))
		return (NULL);
	s[i--] = 0;
	while (n)
	{
		s[i--] = b[n % base];
		n /= base;
	}
	if (!nb)
		*s = '0';
	if (nb < 0 && base == 10)
		*s = '-';
	return (s);
}

char			*pf_conv_ui(uintmax_t n, int base)
{
	int					i;
	char				*s;
	static char			b[] = "0123456789abcdef";

	i = nb_len(n, base);
	if (!(s = ft_strnew(i)))
		return (NULL);
	s[i--] = 0;
	if (!n)
		*s = '0';
	while (n)
	{
		s[i--] = b[n % base];
		n /= base;
	}
	return (s);
}
