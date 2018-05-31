/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:08:04 by lmartin-          #+#    #+#             */
/*   Updated: 2016/12/16 18:53:17 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define PF_CONV	"sSpbBdDioOuUxXcCn%"
# define PF_FPAD	" #0-+"
# define PF_FMOD	"hjlz"
# define PF_FLAGS	" #0-+hjlz.*"
# define RES_CHR	"\033[0"
# define FG_C		";3"
# define BG_C		";4"
# define BLACK_C	"0"
# define RED_C		"1"
# define GREEN_C	"2"
# define YELLOW_C	"3"
# define BLUE_C		"4"
# define PURPLE_C	"5"
# define CYAN_C		"6"
# define WHITE_C	"7"
# define COL_SIZE	9
# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>
# include "libft.h"

/*
****** FCT *********************************************************************
*/

int		ft_printf(char *fmt, ...);

/*
*** READFMT
*/

char	*pf_wildprec(char *beg, int len, va_list *ap);
char	*pf_parseflags(char *beg, va_list *ap);
int		pf_convert(va_list *ap, char *beg);
int		pf_readfmt(va_list *ap, char **fmt);
int		pf_printfmt(char **fmt);

/*
*** GET
*/

char	*pf_getint(va_list *ap, char *flags);
char	*pf_getoct(va_list *ap, char *flags);
char	*pf_gethex(va_list *ap, char *flags, char cnv);
char	*pf_getbin(va_list *ap, char *flags);
char	*pf_getuint(va_list *ap, char *flags);

int		pf_getchr(va_list *ap, char *flags);
char	*pf_getstr(va_list *ap, char *flags);

char	*pf_getptr(va_list *ap, char *flags);

/*
*** PAD
*/

int		pf_isnull(char *str);
int		pf_getprc(char *flags);
void	pf_getlpad(char **str, int prc, char pad);
void	pf_getrpad(char **str, int prc, char pad);
void	pf_applypads(char **str, char *flags, char cnv);

int		pf_iszflag(char *flags);
void	pf_xpad(char **str, char *flags, int prc);
void	pf_opad(char **str, char *flags, int prc);
void	pf_ipad(char **str, char *flags, int prc);
void	pf_zpad(char **str, char *flags, int prc);

/*
*** CONV
*/

char	*pf_conv_i(intmax_t nb, int base);
char	*pf_conv_ui(uintmax_t n, int base);

char	*pf_convwc(wchar_t wchr);
char	*pf_convws(wchar_t *wstr);

#endif
