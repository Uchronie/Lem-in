/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 17:05:45 by lmartin-          #+#    #+#             */
/*   Updated: 2018/02/11 20:49:07 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H
# include "anthill.h"

int			ft_findpath(t_room *s, int len, int ant_name, int t_num);
int			ft_printmove(int ant, char *room_name);

#endif
