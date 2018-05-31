/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 01:23:11 by lmartin-          #+#    #+#             */
/*   Updated: 2017/12/03 14:46:40 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "anthill.h"

void	free_room(t_room *room)
{
	t_list *tmp;

	while (room->tun)
	{
		tmp = room->tun;
		room->tun = tmp->next;
		free(tmp);
	}
	free(room->name);
}
