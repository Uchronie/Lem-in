/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:09:34 by lmartin-          #+#    #+#             */
/*   Updated: 2017/07/06 18:00:55 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnstr(const char *s, size_t n)
{
	size_t len;

	len = ft_strlen(s);
	write(1, s, (n < len) ? n : len);
}
