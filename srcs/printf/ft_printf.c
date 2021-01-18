/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 22:29:17 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/08/13 16:35:47 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** -----------------------------------------------------------------------------
** %とft_isconvert()の間で、フォーマットを決める
** 出力する文字数とフォーマット構文の文字数を把握する必要あり
** 決まったフォーマットで出力する
** フォーマット構文の分formatのポインタを進める
** %[flag(-/0)][field].[precision][format char]
**
** それ以外の時は1文字ずつ出力する
** -----------------------------------------------------------------------------
*/

static void	my_putchar_increment(const char **format, size_t *wc)
{
	ft_putchar_fd(**format, 1);
	*format += 1;
	*wc += 1;
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	wc;

	va_start(ap, format);
	wc = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (!(ft_strisf(format + 1, ft_isconvert)))
			{
				va_arg(ap, int);
				format = ft_strisf(format + 1, ft_isnotformat);
			}
			else
			{
				wc += ft_putformat(format, ap);
				format = ft_strisf(format + 1, ft_isconvert) + 1;
			}
		}
		else
			my_putchar_increment(&format, &wc);
	}
	va_end(ap);
	return (wc);
}
