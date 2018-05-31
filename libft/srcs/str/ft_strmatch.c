/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 09:10:34 by lmartin-          #+#    #+#             */
/*   Updated: 2017/10/09 09:11:38 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strmatch(char *s1, char *s2)
{
	if (!*s1 && !*s2)
		return (1);
	if (!*s2 && *s1 == '*')
		return (ft_strmatch(s1 + 1, s2));
	if (*s1 == '\\' && *(s1 + 1) == *s2)
		return (ft_strmatch(s1 + 2, s2 + 1));
	if (*s1 == '*')
		return (ft_strmatch(s1 + 1, s2) || ft_strmatch(s1, s2 + 1));
	if (*s1 == *s2 || (*s1 == '?' && *s2))
		return (ft_strmatch(s1 + 1, s2 + 1));
	return (0);
}
