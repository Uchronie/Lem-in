/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 14:20:27 by lmartin-          #+#    #+#             */
/*   Updated: 2018/04/06 14:47:39 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "err.h"

static void	print_token(char *token, int last)
{
	write(2, "`", 1);
	write(2, token, ft_strlen(token));
	write(2, "`", 1);
	if (!last)
		write(2, ", ", 2);
}

void		syntax_error(char chr, char *token, char *line, size_t index)
{
	if (token == NULL)
		fatal_error(MALLOC_ERROR, EXIT_FAILURE);
	write(2, ERR_PREFIX, ft_strlen(ERR_PREFIX));
	write(2, "Syntax error: ", 14);
	print_token(&chr, 0);
	print_token(token, 0);
	print_token(line, 1);
	write(2, " on line ", 9);
	ft_putnbr_fd(index, 2);
	write(2, "\n", 1);
	free(token);
}
