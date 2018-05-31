/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 22:41:00 by lmartin-          #+#    #+#             */
/*   Updated: 2018/04/06 14:33:27 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include "anthill.h"
# include "parser.h"
# include "err.h"

/*
***** FUNCTION *****************************************************************
*/

/*
*** PARSER
*/

t_hill	*li_parser(int fd);

/*
*** ALGO
*/

int		li_algo(t_room *s);
int		ft_move(t_room *start, int nba);

#endif
