/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 23:59:42 by lmartin-          #+#    #+#             */
/*   Updated: 2018/02/11 20:31:25 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

int				ft_printmove(int ant, char *room_name)
{
	static int n = 0;

	if (n == 0)
		n = ant + 1;
	write(1, "L", 1);
	ft_putnbr(n - ant);
	write(1, "-", 1);
	ft_putstr(room_name);
	write(1, " ", 1);
	return (1);
}

static void		ft_findtun(t_room *s, int len, t_list *tmp, int t_num)
{
	int n;

	n = -1;
	if ((ACCESS_TUNNEL(tmp))->pos >= 0 && (ACCESS_TUNNEL(tmp))->end != FRONT_E)
	{
		if (s->end != FRONT_E && s->pos - 1 == (ACCESS_TUNNEL(tmp))->pos)
		{
			if (s->turn != t_num)
				n = ft_findpath((ACCESS_TUNNEL(tmp)), len, s->ants, t_num);
			else
				n = ft_findpath((ACCESS_TUNNEL(tmp)), len, 0, t_num);
		}
		else if (s->end == FRONT_E)
		{
			if ((ACCESS_TUNNEL(tmp))->pos == len
			|| s->ants >= (ACCESS_TUNNEL(tmp))->pos)
				n = ft_findpath((ACCESS_TUNNEL(tmp)), len, s->ants, t_num);
			else if (s->ants < (ACCESS_TUNNEL(tmp))->pos)
				n = ft_findpath((ACCESS_TUNNEL(tmp)), len, 0, t_num);
		}
		if (n >= 0)
			s->ants = (s->end == FRONT_E) ? s->ants - 1 : 0;
	}
}

int				ft_findpath(t_room *s, int len, int ant_name, int t_num)
{
	static int	n = 0;
	t_list		*tmp;

	tmp = s->tun;
	if (s->end == FRONT_E)
		n = 0;
	if (s->end == BACK_E)
	{
		if (ant_name > 0 && ft_printmove(ant_name, s->name))
			return (++n);
		return (-1);
	}
	while (tmp)
	{
		ft_findtun(s, len, tmp, t_num);
		tmp = tmp->next;
	}
	if (ant_name > 0 && s->ants == 0)
	{
		s->ants = ant_name;
		s->turn = t_num;
		ft_printmove(ant_name, s->name);
		return (1);
	}
	return ((s->end == FRONT_E) ? n : -1);
}

int				ft_move(t_room *start, int nba)
{
	int			ants;
	t_list		*tmp;
	int			len;
	int			n;

	n = 0;
	tmp = start->tun;
	len = 2147483647;
	while (start->tun)
	{
		if (((t_room *)(start->tun->content))->pos > 0 &&
		(((t_room *)(start->tun->content))->pos < len))
			len = (((t_room *)(start->tun->content))->pos);
		start->tun = start->tun->next;
	}
	start->tun = tmp;
	ants = 0;
	start->ants = nba;
	while (nba > ants)
	{
		ants += ft_findpath(start, len, 0, ++n);
		write(1, "\n", 1);
	}
	return (1);
}
