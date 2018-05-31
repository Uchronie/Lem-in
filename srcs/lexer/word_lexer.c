/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 11:53:26 by lmartin-          #+#    #+#             */
/*   Updated: 2018/04/06 14:49:47 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "err.h"

static t_slex	translate(t_clex chr, t_slex cur)
{
	if (cur == TAG_S || (cur == COM_S))
		return (cur);
	if (chr == GENERAL_C && (cur == NONE_S || cur == NAME_S || cur == COORD_S))
		return (NAME_S);
	if (chr == NUMBER_C && (cur == NONE_S || cur == COORD_S))
		return (COORD_S);
	if (chr == NUMBER_C && cur == NAME_S)
		return (NAME_S);
	if (chr == TAG_C && (cur == NAME_S || cur == COORD_S))
		return (NAME_S);
	if (chr == TAG_C && cur == NONE_S)
		return (TCOM_S);
	if (chr == TAG_C && cur == TCOM_S)
		return (TAG_S);
	if (chr == TUN_C && (cur == NAME_S || cur == COORD_S))
		return (TUN_S);
	if ((chr == GENERAL_C || chr == NUMBER_C || chr == TAG_C)
			&& (cur == TUN_S))
		return (TUN_S);
	if (cur == TCOM_S)
		return (COM_S);
	return (NONE_S);
}

t_slex			word_lexer(char **word, size_t index)
{
	t_slex	ret;
	t_clex	chr;
	char	*line;
	char	*tmp;

	ret = NONE_S;
	line = *word;
	while ((chr = char_lexer(**word)) != IFS_C)
	{
		if ((ret = translate(chr, ret)) == NONE_S)
		{
			tmp = ft_strchr(*word, ' ');
			tmp = (tmp) ? tmp : ft_strchr(*word, '\0');
			syntax_error(**word, ft_strndup(*word, tmp - *word), line, index);
			return (NONE_S);
		}
		(*word)++;
	}
	return (ret);
}
