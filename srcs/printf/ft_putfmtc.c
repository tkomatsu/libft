/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfmtc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 19:39:51 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/08/01 22:39:55 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** -----------------------------------------------------------------------------
** caller: ft_putconvert
**
** put formatted character and return output length
**
** 1. フラグ対応
**   '-': 左づめ対応。attribute.minus == 1の場合対応
**
** 2. フィールド対応
**   attribute.field > length of formatted stringのとき
**   '-'フラグがついている場合
**     文末に' 'をいれる
**   '-'フラグがついていない場合
**     文頭に' 'をいれる
** -----------------------------------------------------------------------------
*/

static void	my_putfmtc(t_fmt attribute, va_list ap)
{
	unsigned char	*ans;
	size_t			i;
	size_t			len;

	i = 0;
	len = attribute.field;
	if (!(ans = ft_calloc(len + 1, sizeof(char))))
	{
		free(ans);
		return ;
	}
	if (attribute.minus)
	{
		ans[0] = va_arg(ap, int);
		while (++i < len)
			ans[i] = ' ';
	}
	else
	{
		ans[len - 1] = va_arg(ap, int);
		while (i < len - 1)
			ans[i++] = ' ';
	}
	write(1, ans, len);
}

size_t		ft_putfmtc(t_fmt attribute, va_list ap)
{
	unsigned char	*ans;
	size_t			len;

	if (attribute.field)
	{
		len = attribute.field;
		my_putfmtc(attribute, ap);
	}
	else
	{
		if (!(ans = ft_calloc(2, sizeof(char))))
		{
			free(ans);
			return (0);
		}
		ans[0] = va_arg(ap, int);
		len = 1;
		write(1, ans, len);
	}
	return (len);
}
