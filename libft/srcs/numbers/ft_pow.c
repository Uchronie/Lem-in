/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 01:31:06 by lmartin-          #+#    #+#             */
/*   Updated: 2016/11/08 02:16:39 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_pow(int n, int pow)
{
	if (pow > 0)
		return (n * ft_pow(n, --pow));
	return (!pow);
}
