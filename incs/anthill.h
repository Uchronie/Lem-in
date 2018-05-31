/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 21:57:10 by lmartin-          #+#    #+#             */
/*   Updated: 2018/02/11 20:41:53 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANTHILL_H
# define ANTHILL_H
# define ACCESS_TUNNEL(tmp) (t_room *)(tmp->content)
# include "libft.h"

/*
****** ENUM ********************************************************************
*/

typedef enum e_end		t_end;
enum					e_end
{
	MID_E,
	FRONT_E,
	BACK_E,
	NOT_E
};

/*
****** STRUCT ******************************************************************
*/

typedef struct s_room	t_room;
struct					s_room
{
	int				ants;
	int				pos;
	int				turn;
	t_end			end;
	char			*name;
	t_list			*tun;
};

typedef struct s_hill	t_hill;
struct					s_hill
{
	int				ants;
	t_room			*start;
	t_room			*end;
};

#endif
