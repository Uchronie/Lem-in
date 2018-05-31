/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 00:29:55 by lmartin-          #+#    #+#             */
/*   Updated: 2017/11/03 09:14:53 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

static int	read_line(const int fd, char **line, char (*cache)[])
{
	char			buff[BUFF_SIZE + 1];
	char			*endl;
	int				rd;
	int				ret;

	ret = (**line != 0);
	while ((rd = read(fd, buff, BUFF_SIZE)))
	{
		if ((ret = 1) && rd == -1)
			return (-1);
		buff[rd] = 0;
		if ((endl = ft_strchr(buff, '\n')))
		{
			*(endl++) = 0;
			ft_strcpy(*cache, endl);
			if (!(*line = ft_strjoinfree(*line, buff, 1)))
				return (-1);
			return (1);
		}
		if (!(*line = ft_strjoinfree(*line, buff, 1)))
			return (-1);
	}
	(!ret) ? free(*line) : ret;
	*line = (!ret) ? NULL : *line;
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	static char		cache[BUFF_SIZE + 1] = "";
	char			*endl;

	if (!line || fd < 0)
		return (-1);
	if (!(*line = ft_strdup(cache)))
		return (-1);
	if ((endl = ft_strchr(*line, '\n')))
	{
		ft_strcpy(cache, (endl + 1));
		*endl = 0;
		return (1);
	}
	ft_strclr(cache);
	if (!**line)
		return (read_line(fd, line, &cache));
	if (read_line(fd, line, &cache) == -1)
	{
		free(line);
		return (-1);
	}
	return (1);
}
