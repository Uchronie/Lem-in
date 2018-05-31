/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 22:40:08 by lmartin-          #+#    #+#             */
/*   Updated: 2017/12/03 14:46:06 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# define HASH_SIZE	1000000
# include <stdlib.h>
# include "libft.h"
# include "anthill.h"

/*
****** ENUM ********************************************************************
*/

typedef enum e_hins	t_hins;
enum				e_hins
{
	GET_HSH,
	INSERT_HSH,
	INIT_HSH,
	FREE_HSH
};

/*
****** FUNCTIONS ***************************************************************
*/

t_room			*hash_access(t_hins inst, char *index, t_room *add);
t_room			**parse_rooms(int fd, char **lcur);
void			parse_tunnels(int fd, char **lcur);

void			free_room(t_room *room);

#endif
