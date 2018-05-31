/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 13:37:34 by lmartin-          #+#    #+#             */
/*   Updated: 2018/04/06 15:25:07 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_H
# define ERR_H
# define ERR_PREFIX		"lem_in: "
# define MALLOC_ERROR	"not enough data"
# define PATH_ERROR		"Could not find path to exit"
# define FILE_ERROR		"Could not open file"
# define ANT_ERROR		"First non-commentary line is not a valid number"
# include <string.h>

void	fatal_error(char *message, int code);
void	syntax_error(char chr, char *token, char *line, size_t index);

#endif
