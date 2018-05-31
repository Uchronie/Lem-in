/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 10:46:53 by lmartin-          #+#    #+#             */
/*   Updated: 2018/04/06 14:44:56 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "libft.h"

/*
****** ENUMS *******************************************************************
*/

typedef enum e_clex	t_clex;
enum				e_clex
{
	GENERAL_C,
	NUMBER_C = '0',
	TUN_C = '-',
	TAG_C = '#',
	IFS_C = ' ',
	NONE_C = -1
};

typedef enum e_slex	t_slex;
enum				e_slex
{
	NAME_S,
	COORD_S,
	TUN_S,
	TCOM_S,
	COM_S,
	TAG_S,
	NONE_S = -1
};

typedef enum e_llex	t_llex;
enum				e_llex
{
	ROOM_L,
	TUN_L,
	COM_L,
	TAG_L,
	NONE_L = -1
};

/*
****** FUNCTIONS ***************************************************************
*/

t_llex			li_lexer(char *line);

t_clex			char_lexer(char chr);
t_slex			word_lexer(char **word, size_t index);

#endif
