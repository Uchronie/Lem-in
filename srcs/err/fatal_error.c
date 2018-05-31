/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 13:35:44 by lmartin-          #+#    #+#             */
/*   Updated: 2018/04/06 13:51:30 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "parser.h"
#include "err.h"

void	fatal_error(char *message, int code)
{
	hash_access(FREE_HSH, NULL, NULL);
	write(2, ERR_PREFIX, ft_strlen(ERR_PREFIX));
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	exit(code);
}
