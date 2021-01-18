/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:58:31 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/18 20:06:33 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# include "libft.h"

/*
** -----------------------------------------------------------------------------
** 型定義
** -----------------------------------------------------------------------------
*/

typedef struct	s_fmt
{
	size_t	zero;
	size_t	minus;
	int		field;
	int		precision;
	char	sign;
	int		capital;
	int		base;
}				t_fmt;

/*
** -----------------------------------------------------------------------------
** utility
** -----------------------------------------------------------------------------
*/

char			ft_itoc(int c);
int				ft_isflag(int c);
int				ft_isconvert(int c);
int				ft_isnotformat(int c);
void			ft_putpad(size_t len, char padchar);
size_t			ft_numlen(long long num, int base);

/*
** -----------------------------------------------------------------------------
** 判定関数
** -----------------------------------------------------------------------------
*/

t_fmt			ft_getattribute(const char *format, va_list ap);

/*
** -----------------------------------------------------------------------------
** 変換・出力関数
** -----------------------------------------------------------------------------
*/

size_t			ft_putfmtc(t_fmt attribute, va_list ap);
size_t			ft_putfmts(t_fmt attribute, va_list ap);
size_t			ft_putfmtdi(t_fmt attribute, va_list ap);
size_t			ft_putfmtux(t_fmt attribute, va_list ap, char conv);
size_t			ft_putfmtp(t_fmt attribute, va_list ap);
size_t			ft_putfmtpercent(t_fmt attribute);
void			ft_putintpre(t_fmt attribute, long num);
void			ft_putintpad(t_fmt attribute, long num);

/*
** -----------------------------------------------------------------------------
** 制御関数
** -----------------------------------------------------------------------------
*/

size_t			ft_putconvert(const char *format, t_fmt attribute, va_list ap);
size_t			ft_putformat(const char *format, va_list ap);
int				ft_printf(const char *format, ...);

#endif
