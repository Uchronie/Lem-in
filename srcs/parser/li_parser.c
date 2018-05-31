/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 22:47:28 by lmartin-          #+#    #+#             */
/*   Updated: 2018/04/06 15:26:14 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "lexer.h"
#include "err.h"

static int	check_ants(int fd)
{
	char	*lcur;
	char	*tmp;
	int		ret;

	lcur = NULL;
	while (!lcur || *lcur == '#')
	{
		free(lcur);
		if ((ret = get_next_line(fd, &lcur)) == 0)
			return (ret);
		ft_putendl(lcur);
	}
	tmp = lcur;
	while (*tmp)
		if (48 > *tmp || *(tmp++) > 57)
			return (-2);
	ret = ft_atoi(lcur);
	free(lcur);
	return (ret);
}

t_hill		*li_parser(int fd)
{
	t_hill	*hill;
	t_room	**tmp;
	char	*lcur;

	if (!(hill = malloc(sizeof(t_hill))))
		fatal_error(MALLOC_ERROR, EXIT_FAILURE);
	if ((hill->ants = check_ants(fd)) < 1)
	{
		fd = hill->ants;
		free(hill);
		fatal_error((fd < 1) ? ANT_ERROR : FILE_ERROR, EXIT_FAILURE);
	}
	hash_access(INIT_HSH, NULL, NULL);
	lcur = NULL;
	tmp = parse_rooms(fd, &lcur);
	hill->start = tmp[0];
	hill->end = tmp[1];
	free(tmp);
	if (lcur != NULL)
		parse_tunnels(fd, &lcur);
	return (hill);
}
