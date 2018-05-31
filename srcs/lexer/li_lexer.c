/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 10:46:32 by lmartin-          #+#    #+#             */
/*   Updated: 2017/10/16 01:22:19 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static t_llex	translate(t_slex word, t_llex cur)
{
	if ((word == NAME_S || word == COORD_S) && cur == NONE_L)
		return (ROOM_L);
	if (word == COORD_S && cur == ROOM_L)
		return (ROOM_L);
	if (word == TUN_S && cur == NONE_L)
		return (TUN_L);
	if (word == TAG_S && cur == NONE_L)
		return (TAG_L);
	if (word == COM_S && cur == NONE_L)
		return (COM_L);
	return (NONE_L);
}

t_llex			li_lexer(char *line)
{
	t_llex			ret;
	t_slex			word;
	char			*next;
	static size_t	index = 0;

	ret = NONE_L;
	next = line;
	while (*line)
	{
		word = word_lexer(&next, index);
		if ((ret = translate(word, ret)) == NONE_L)
			return (NONE_L);
		while (*next && char_lexer(*next) == IFS_C)
			next++;
		line = next;
	}
	index++;
	return (ret);
}
