/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:09:28 by lmartin-          #+#    #+#             */
/*   Updated: 2018/02/11 21:24:42 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

int		li_algo(t_room *s)
{
	static int	nb = -1;
	int			c;
	t_list		*tmp;

	tmp = s->tun;
	nb++;
	c = (s->pos < 0) ? -1 : s->pos;
	if (s->end == FRONT_E && !(s->pos = 0))
		return (nb--);
	if (s->end == BACK_E)
		s->pos = 0;
	s->pos = (s->pos != -2 && s->pos < nb) ? s->pos : nb;
	while (tmp)
	{
		if ((ACCESS_TUNNEL(tmp))->end == BACK_E)
			c = 1;
		if ((ACCESS_TUNNEL(tmp))->pos == -2 ||
(ACCESS_TUNNEL(tmp))->pos > nb + 1 || (ACCESS_TUNNEL(tmp))->end == FRONT_E)
			c = li_algo(ACCESS_TUNNEL(tmp));
		tmp = tmp->next;
	}
	if (c == -1 && s->end != BACK_E)
		s->pos = c;
	return (--nb);
}
