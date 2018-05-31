/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 13:22:48 by lmartin-          #+#    #+#             */
/*   Updated: 2018/04/06 14:51:33 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_clex	char_lexer(char chr)
{
	if (chr == ' ' || chr == '\t' || !chr)
		return (IFS_C);
	if (33 > chr || chr > 126)
		return (NONE_C);
	if (48 <= chr && chr <= 57)
		return (NUMBER_C);
	if (chr == '#' || chr == '-')
		return (chr);
	return (GENERAL_C);
}
