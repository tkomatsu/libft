/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfmts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 08:22:36 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/08/01 22:40:58 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** -----------------------------------------------------------------------------
** caller: ft_putconvert
**
** put formatted string and return output length
**
** 1. フラグ対応
**   '-': 左づめ対応。attribute.minus == 1の場合対応
**   '0': '-'フラグがついている場合は0で埋める
**
** 2. フィールド対応
**   attribute.field > length of formatted stringのとき
**   '-'フラグがついている場合
**     文末に' 'をいれる
**   '-'フラグがついていない場合
**     文頭に' 'をいれる
**
** 3. 精度対応
**   attribute.precision >= 0のとき
**   文字列から出力する最大文字数を精度指定の値にする
**
** 4. ヌルポインタ対応
**   引数の文字列がヌルポインタだった場合出力する文字列を"(null)"とする
** -----------------------------------------------------------------------------
*/

size_t	ft_putfmts(t_fmt attribute, va_list ap)
{
	char	*ans;
	int		width;
	int		i;

	i = attribute.field;
	ans = va_arg(ap, char *);
	if (ans == NULL)
		ans = "(null)";
	width = ft_strlen(ans);
	if (0 <= attribute.precision && attribute.precision < width)
		width = attribute.precision;
	if (0 <= attribute.field && width < attribute.field)
	{
		i = 0;
		if (attribute.minus == 0)
			while (i++ < (attribute.field - width))
				write(1, (attribute.zero == 0 ? " " : "0"), 1);
		write(1, ans, width);
		while (i++ < (attribute.field - width))
			write(1, " ", 1);
	}
	else
		write(1, ans, width);
	return (attribute.field > width ? attribute.field : width);
}
