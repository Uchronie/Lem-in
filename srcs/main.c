/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 22:39:49 by lmartin-          #+#    #+#             */
/*   Updated: 2018/04/06 15:22:28 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "lem_in.h"

int		main(int ac, char **av)
{
	int		fd;
	t_hill	*hill;

	fd = 0;
	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			fatal_error(FILE_ERROR, EXIT_FAILURE);
	}
	hill = li_parser(fd);
	write(1, "\n", 1);
	if (hill == NULL)
		return (EXIT_FAILURE);
	if (hill->start != NULL && hill->end != NULL)
		li_algo(hill->end);
	if (hill->start == NULL || hill->start->pos != 0)
	{
		free(hill);
		fatal_error(PATH_ERROR, EXIT_FAILURE);
	}
	ft_move(hill->start, hill->ants);
	hash_access(FREE_HSH, NULL, NULL);
	if (fd != 0)
		close(fd);
	return (EXIT_SUCCESS);
}
