/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_readfmt2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 23:28:43 by lmartin-          #+#    #+#             */
/*   Updated: 2016/12/03 16:51:17 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_getfbg(char *fmt, char color[])
{
	if (*(fmt + 1) == 'b')
		ft_strcat(color, BG_C);
	else
		ft_strcat(color, FG_C);
}

static int	pf_getcolor(char *fmt, char color[], size_t n)
{
	if (ft_strnstr(fmt, "eoc", n))
		return (1);
	else if (ft_strnstr(fmt, "black", n))
		ft_strcat(color, BLACK_C);
	else if (ft_strnstr(fmt, "red", n))
		ft_strcat(color, RED_C);
	else if (ft_strnstr(fmt, "green", n))
		ft_strcat(color, GREEN_C);
	else if (ft_strnstr(fmt, "yellow", n))
		ft_strcat(color, YELLOW_C);
	else if (ft_strnstr(fmt, "blue", n))
		ft_strcat(color, BLUE_C);
	else if (ft_strnstr(fmt, "purple", n))
		ft_strcat(color, PURPLE_C);
	else if (ft_strnstr(fmt, "cyan", n))
		ft_strcat(color, CYAN_C);
	else if (ft_strnstr(fmt, "white", n))
		ft_strcat(color, WHITE_C);
	else
		return (0);
	return (1);
}

static int	pf_printcolor(char **fmt)
{
	char	color[COL_SIZE + 1];
	char	*end;
	size_t	n;
	int		i;

	ft_strcpy(color, RES_CHR);
	end = ft_strchr(*fmt, '}') + 1;
	n = end - *fmt - 1;
	if (ft_strnstr(*fmt, ":", n) && (i = 1))
	{
		(!ft_strnstr(*fmt, "eoc", n)) ? pf_getfbg(*fmt, color) : *fmt;
		end = ft_strchr(*fmt, ':');
		n = end - *fmt - 1;
		i = pf_getcolor(*fmt, color, n);
	}
	else
	{
		(!ft_strnstr(*fmt, "eoc", n)) ? ft_strcat(color, FG_C) : *fmt;
		i = pf_getcolor(*fmt, color, n);
	}
	ft_strcat(color, "m");
	(i) ? ft_putstr(color) : i;
	*fmt = (!i) ? *fmt : end;
	i = (!i) ? 0 : ft_strlen(color);
	return (i);
}

static int	pf_readcolor(char **fmt)
{
	char	*next_stop;
	int		len;

	if (!(next_stop = ft_strchr(*fmt, '{')))
		return (0);
	if (**fmt != '{' || !ft_strchr(*fmt, '}'))
	{
		len = next_stop - *fmt;
		ft_putnstr(*fmt, len);
		*fmt = next_stop;
		return (len);
	}
	return (pf_printcolor(fmt));
}

int			pf_printfmt(char **fmt)
{
	int		len;
	char	*next_stop;

	len = 0;
	if (!(next_stop = ft_strchr(*fmt, '%')))
	{
		if ((len = pf_readcolor(fmt)))
			return (len);
		next_stop = *fmt;
		ft_putstr(next_stop);
		*fmt += ft_strlen(*fmt);
		return (ft_strlen(next_stop));
	}
	if (**fmt != '%' && next_stop)
	{
		if (!(len += pf_readcolor(fmt)))
		{
			len += next_stop - *fmt;
			ft_putnstr(*fmt, len);
			*fmt = next_stop;
		}
		return (len);
	}
	return (0);
}
