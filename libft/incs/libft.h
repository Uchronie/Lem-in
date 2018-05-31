/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmartin- <lmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 01:27:36 by lmartin-          #+#    #+#             */
/*   Updated: 2017/11/03 16:35:23 by lmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>

/*
****** STRUCT ******************************************************************
*/

typedef struct s_btree	t_btree;
struct					s_btree
{
	void				*data;
	size_t				size;
	t_btree				*left;
	t_btree				*right;
};

typedef struct s_list	t_list;
struct					s_list
{
	void				*content;
	size_t				content_size;
	t_list				*next;
};

/*
****** PUT *********************************************************************
*/

int						ft_putchar(int c);
void					ft_putnchar(char c, int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr(const char *s);
void					ft_putnstr(const char *s, size_t n);
void					ft_putstr_fd(const char *s, int fd);
void					ft_putendl(const char *s);
void					ft_putendl_fd(const char *s, int fd);
void					ft_putnbr(int n);
void					ft_putnbr_fd(int n, int fd);
void					ft_putbase(int n, int b);
void					ft_putlst(t_list *elem);

/*
****** MEMORY ******************************************************************
*/

void					*ft_memset(void *s, int c, size_t n);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memccpy(void *dest, const void *src, int c,
									size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memalloc(size_t size);
void					*ft_memrealloc(void **ap, size_t size);
void					ft_memdel(void **ap);
void					ft_print_memory(const void *addr, size_t size);
void					*ft_memicpy(void *dest, const void *src, size_t n);
void					*ft_memlcpy(void *dest, const void *src, size_t n);

/*
****** STRING ******************************************************************
*/

size_t					ft_strlen(const char *s);
size_t					ft_strclen(const char *s, int c);
char					*ft_strdup(const char *s);
char					*ft_strcdup(const char *s, int c);
char					*ft_strndup(const char *s, size_t n);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strccpy(char *dst, const char *src, int c);
char					*ft_strncpy(char *dst, const char *src, size_t len);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *big, const char *little);
char					*ft_strnstr(const char *big, const char *little,
									size_t len);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char*));
char					*ft_strmap(const char *s, char (*f)(char));
char					*ft_strmapi(const char *s,
									char (*f)(unsigned int, char));
int						ft_strequ(const char *s1, const char *s2);
int						ft_strnequ(const char *s1, const char *s2, size_t n);
char					*ft_strsub(const char *s, unsigned int start,
									size_t len);
char					*ft_strjoin(const char *s1, const char *s2);
char					*ft_strtrim(const char *s);
char					*ft_strrev(char *s);
char					**ft_strsplit(const char *s, char c);
char					*ft_strjoinfree(char *s1, char *s2, int which);
int						ft_strcount(char *s, char c);
int						ft_strnum(const char *s);
int						ft_strmatch(char *s1, char *s2);

int						ft_tablen(char **ttab);
char					**ft_tabcpy(char **env);
void					ft_tabfree(char **ttab);

/*
****** ISCLASS *****************************************************************
*/

int						ft_isupper(int c);
int						ft_islower(int c);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);

/*
****** TOCLASS *****************************************************************
*/

int						ft_toupper(int c);
int						ft_tolower(int c);

/*
****** NUMBERS *****************************************************************
*/

int						ft_pow(int n, int pow);

/*
****** CONVERT *****************************************************************
*/

int						ft_atoi(const char *nptr);
char					*ft_itoa(int n);
int						ft_atoi_base(const char *s, const int b);
char					*ft_itoa_base(int n, const int b);

/*
****** LISTS *******************************************************************
*/

t_list					*ft_lstnew(const void *content, size_t content_size);
void					ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void					ft_lstappend(t_list **alst, t_list *new);
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list					*ft_lstfind(t_list *lst, int (*f)(void*), int value);
t_list					*ft_lstlast(t_list *lst);
void					ft_lstremove_if(t_list **lst, int (*f)(void*),
										int value);
void					ft_lstfree(t_list **lst);
void					ft_lstfree_elem(t_list **lst);
int						ft_lstlen(t_list *lst);
void					ft_lstswap(t_list *a, t_list *b);
void					ft_lstsort(t_list *lst, int (*cmp)(void*, void*));
t_list					*ft_lstcpy(t_list *lst);

/*
****** BTREE *******************************************************************
*/

t_btree					*ft_btnode(void *data, size_t size);
void					ft_btaddlr(t_btree **atr, t_btree *new,
									int (*cmpf)(void *, void *));
void					ft_btaddrl(t_btree **atr, t_btree *new,
									int (*cmpf)(void *, void *));
void					ft_btfree(t_btree **root, int free_data);
size_t					ft_btdensity(t_btree *root);
size_t					ft_btdepth(t_btree *root);

/*
****** GNL *********************************************************************
*/

int						get_next_line(const int fd, char **line);
int						ft_printf(char *fmt, ...);

#endif
