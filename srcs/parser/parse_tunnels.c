/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tunnels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:20:39 by lmartin-          #+#    #+#             */
/*   Updated: 2018/04/06 13:50:04 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "lexer.h"
#include "err.h"

static void	create_link(t_room *side1, t_room *side2)
{
	t_list *new1;
	t_list *new2;

	if (!(new1 = malloc(sizeof(t_list))))
		fatal_error(MALLOC_ERROR, EXIT_FAILURE);
	if (!(new2 = malloc(sizeof(t_list))))
		fatal_error(MALLOC_ERROR, EXIT_FAILURE);
	new1->next = NULL;
	new1->content = side2;
	new1->content_size = sizeof(t_room);
	new2->next = NULL;
	new2->content = side1;
	new2->content_size = sizeof(t_room);
	ft_lstadd(&side1->tun, new1);
	ft_lstadd(&side2->tun, new2);
}

static char	*clear_str(char *word)
{
	char *tmp;

	while (char_lexer(*word) == IFS_C)
		word++;
	tmp = word;
	if ((tmp = ft_strchr(tmp, ' ')))
		*tmp = 0;
	tmp = word;
	if ((tmp = ft_strchr(tmp, '\t')))
		*tmp = 0;
	return (word);
}

static void	add_link(char *tun)
{
	t_room	*room1;
	t_room	*room2;
	char	*tun2;

	tun = clear_str(tun);
	if (!*((tun2 = ft_strchr(tun, '-')) + 1))
		fatal_error(MALLOC_ERROR, EXIT_FAILURE);
	*tun2++ = 0;
	if (!(room1 = hash_access(GET_HSH, tun, NULL)))
		fatal_error(MALLOC_ERROR, EXIT_FAILURE);
	if (!(room2 = hash_access(GET_HSH, tun2, NULL)))
		fatal_error(MALLOC_ERROR, EXIT_FAILURE);
	create_link(room1, room2);
}

void		parse_tunnels(int fd, char **lcur)
{
	t_llex	type;
	int		rd;

	while ((type = li_lexer(*lcur)) == TUN_L || type == COM_L)
	{
		if (type == TUN_L)
			add_link(*lcur);
		free(*lcur);
		if ((rd = get_next_line(fd, lcur)) != 1)
		{
			if (!rd)
				break ;
			fatal_error(MALLOC_ERROR, EXIT_FAILURE);
		}
		ft_putendl(*lcur);
	}
	free(*lcur);
	if (type ^ TUN_S)
		return ;
}
