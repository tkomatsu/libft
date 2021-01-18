/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 22:43:15 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/18 20:05:46 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <errno.h>

# include "ft_printf.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define STATIC_MAX 10

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/*
** *****************************************************************************
** memory library
** *****************************************************************************
*/

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** *****************************************************************************
** string library
** *****************************************************************************
*/

size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strcat(char *dst, const char *src);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *haystack, const char *needle,
							size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *s);
double			ft_atof(const char *s);
char			*ft_strisf(const char *s, int (*f)(int));

/*
** *****************************************************************************
** character library
** *****************************************************************************
*/

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/*
** *****************************************************************************
** string library (with malloc)
** *****************************************************************************
*/

void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *src);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
void			ft_free_split(char **strs);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_free(void *ptr);

/*
** *****************************************************************************
** put library
** *****************************************************************************
*/

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
** *****************************************************************************
** t_lst library
** *****************************************************************************
*/

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
							void (*del)(void *));
void			ft_lstsort(t_list **lst, int (*f)(void*, void*));

/*
** *****************************************************************************
** get_next_line
** *****************************************************************************
*/

int				get_next_line(int fd, char **line);

/*
** *****************************************************************************
** error management
** *****************************************************************************
*/

int				ft_puterr(char *s, int errno);

/*
** *****************************************************************************
** environment variable
** *****************************************************************************
*/
char			*ft_getenv(const char *name);
int				ft_setenv(const char *name, const char *value, int overwrite);
int				ft_putenv(const char *string);

#endif
