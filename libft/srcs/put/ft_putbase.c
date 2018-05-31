/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:26:15 by lmartin-          #+#    #+#             */
/*   Updated: 2017/10/09 10:03:19 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putbase(int n, int b)
{
	static char base[] = "0123456789abcdefghiklmnopq";

	if (b == 10 || n == 0)
	{
		ft_putnbr(n);
		return ;
	}
	if (b < 2 || b > 26)
		return ;
	if (n > b - 1)
		ft_putbase(n / b, b);
	ft_putchar(base[n % b]);
}
