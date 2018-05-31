/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:47:12 by lmartin-          #+#    #+#             */
/*   Updated: 2017/11/03 16:34:44 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putprint(const unsigned char *s, size_t n)
{
	while (*s && n--)
	{
		if (ft_isprint(*s))
			write(1, s, 1);
		else
			write(1, ".", 1);
		s++;
	}
}

void		ft_print_memory(const void *addr, size_t size)
{
	unsigned char	*ad;
	size_t			i;
	size_t			j;

	ad = (unsigned char*)addr;
	i = 0;
	while (i < size)
	{
		if (*ad < 16)
			write(1, "0", 1);
		ft_putbase(*(ad++), 16);
		if (!(++i % 2))
			write(1, " ", 1);
		if (!(i % 16) || i == size)
		{
			if (((j = i) % 16))
				while ((j % 16))
				{
					write(1, "  ", 2);
					((j++ % 2)) ? write(1, " ", 1) : i;
				}
			putprint(ad - ((i % 16) ? (i % 16) : 16), 16);
			write(1, "\n", 1);
		}
	}
}
