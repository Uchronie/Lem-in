/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 09:03:11 by lmartin-          #+#    #+#             */
/*   Updated: 2018/04/06 15:35:26 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "lexer.h"
#include "err.h"

static t_end	get_instruct(char *tag)
{
	char		*tmp;
	t_end		ret;

	ret = MID_E;
	tmp = tag;
	while (*tmp && char_lexer(*tmp) == IFS_C)
		tmp++;
	if (!*tmp)
		return (NOT_E);
	tmp = ft_strcpy(tag, tmp);
	while (char_lexer(*tmp) != IFS_C)
		tmp++;
	*tmp = 0;
	if (!ft_strcmp(tag + 2, "start"))
		ret = FRONT_E;
	else if (!ft_strcmp(tag + 2, "end"))
		ret = BACK_E;
	free(tag);
	return (ret);
}

static char		*trunc_name(char *name)
{
	char		*tmp;

	tmp = name;
	while (*tmp && char_lexer(*tmp) == IFS_C)
		tmp++;
	if (!*tmp)
		return (NULL);
	tmp = ft_strcpy(name, tmp);
	while (char_lexer(*tmp) != IFS_C)
		tmp++;
	*tmp = 0;
	return (name);
}

static void		create_room(char *name, t_end end, t_room **start, t_room **ed)
{
	t_room		*room;

	if (!name)
		return ;
	if (!(room = malloc(sizeof(t_room))))
		fatal_error(MALLOC_ERROR, EXIT_FAILURE);
	room->end = end;
	room->name = name;
	room->pos = -2;
	room->ants = 0;
	room->tun = NULL;
	if (end == BACK_E)
		*ed = room;
	else if (end == FRONT_E)
		*start = room;
	hash_access(INSERT_HSH, name, room);
}

static void		parse_room(char **lcur, t_llex type, t_room **ret)
{
	static t_end	end = MID_E;

	if (type == COM_L)
	{
		free(*lcur);
		return ;
	}
	if (type == ROOM_L)
		create_room(trunc_name(*lcur), end, ret, ret + 1);
	end = MID_E;
	if (type == TAG_L)
		end = get_instruct(*lcur);
}

t_room			**parse_rooms(int fd, char **lcur)
{
	t_room		**ret;
	t_llex		type;
	int			rd;

	ret = NULL;
	if (!(ret = malloc(sizeof(t_room *) * 2)))
		fatal_error(MALLOC_ERROR, EXIT_FAILURE);
	ft_bzero(ret, sizeof(t_room *) * 2);
	if ((rd = get_next_line(fd, lcur)) != 1)
		return (ret);
	ft_putendl(*lcur);
	while ((type = li_lexer(*lcur)) != TUN_L)
	{
		if (type == NONE_L)
			return (ret);
		parse_room(lcur, type, ret);
		if ((rd = get_next_line(fd, lcur)) != 1)
			return (ret);
		ft_putendl(*lcur);
	}
	return (ret);
}
