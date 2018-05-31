/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 21:56:07 by lmartin-          #+#    #+#             */
/*   Updated: 2018/04/06 13:50:12 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "err.h"

static size_t	cmpt_key(char *phrase)
{
	size_t	key;
	char	c;

	key = 0xdeadbeef;
	while ((c = *phrase++))
		key = ((key << 7) ^ c) * ((key >> 9));
	return (key % HASH_SIZE);
}

static t_room	*get_hash(t_list *room, char *name)
{
	if (!room)
		return (NULL);
	if (!room->next)
		return (room->content);
	if (!ft_strcmp(name, ((t_room*)room->content)->name))
		return (room->content);
	return (get_hash(room->next, name));
}

static t_list	*insert_hash(t_room *add)
{
	t_list *ret;

	if (!(ret = malloc(sizeof(t_list))))
		fatal_error(MALLOC_ERROR, EXIT_FAILURE);
	ret->content = add;
	ret->content_size = sizeof(t_room);
	ret->next = NULL;
	return (ret);
}

static void		free_hash(t_list **hash_table)
{
	size_t	i;
	t_list	*room;
	t_list	*tmp;

	i = 0;
	while (hash_table != NULL && i < HASH_SIZE)
	{
		if (!hash_table[i] && i++)
			continue ;
		room = hash_table[i++];
		while (room)
		{
			tmp = room;
			room = room->next;
			free_room(tmp->content);
			free(tmp->content);
			free(tmp);
		}
	}
}

t_room			*hash_access(t_hins inst, char *index, t_room *add)
{
	static t_list	**hash_table = NULL;
	size_t			key;

	if (inst == INIT_HSH)
	{
		if (!(hash_table = malloc(HASH_SIZE * sizeof(t_list*))))
			exit(2);
		ft_bzero(hash_table, HASH_SIZE);
		return (NULL);
	}
	if (inst == FREE_HSH)
	{
		free_hash(hash_table);
		free(hash_table);
		return (NULL);
	}
	key = cmpt_key(index);
	if (inst == GET_HSH)
		return (get_hash(hash_table[key], index));
	if (inst != INSERT_HSH)
		return (NULL);
	ft_lstadd((t_list**)&(hash_table[key]), insert_hash(add));
	return (add);
}
