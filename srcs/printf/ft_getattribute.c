/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getattribute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 22:37:54 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/08/16 21:41:44 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
** -----------------------------------------------------------------------------
** caller: ft_putformat
**
** get attribute from format specification
**
** 1. フラグ(flag) 対応(default: 0)
**   1. '-' : attribute.minusを1にする
**   2. '0' : attribute.zeroを1にする
**
** 2. フィールド(field) 対応(default: 0)
**   数字があれば、attribute.fieldに数値をいれる
**
** 3. 精度(precision) 対応(default: -1)
**   '.'があれば0以上の数字をいれる
**   精度の指定がない場合、-1をいれる
**
** 4. '*'があった場合、va_listから値を識別する
**   '*'を最有力とする
** -----------------------------------------------------------------------------
*/

static t_fmt	my_fmtinit(void)
{
	t_fmt	ans;

	ans.minus = 0;
	ans.zero = 0;
	ans.field = 0;
	ans.precision = -1;
	ans.sign = 0;
	ans.capital = 0;
	ans.base = 10;
	return (ans);
}

static int		my_getfield(const char *format, va_list ap, t_fmt *attribute)
{
	int	i;

	i = 0;
	if (ft_isdigit(format[i]))
	{
		attribute->field = (format[i++] - '0');
		while (ft_isdigit(format[i]))
			attribute->field = attribute->field * 10 + (format[i++] - '0');
	}
	else if (format[i] == '*')
	{
		attribute->field = va_arg(ap, int);
		if (attribute->field < 0)
		{
			attribute->minus = 1;
			attribute->field *= -1;
		}
		i++;
	}
	return (i);
}

static int		my_getprecision(const char *format, va_list ap,
								t_fmt *attribute)
{
	int	i;
	int	tmp;

	i = 1;
	if (ft_isdigit(format[i]))
	{
		attribute->precision = (format[i++] - '0');
		while (ft_isdigit(format[i]))
			attribute->precision = attribute->precision * 10 +
				(format[i++] - '0');
	}
	else if (format[i] == '*')
	{
		tmp = va_arg(ap, int);
		if (tmp < 0)
			attribute->precision = -1;
		else
			attribute->precision = tmp;
		i++;
	}
	else
		attribute->precision = 0;
	return (i);
}

t_fmt			ft_getattribute(const char *f, va_list ap)
{
	t_fmt	attribute;

	attribute = my_fmtinit();
	f++;
	while (ft_isflag(*f))
	{
		if (*f == '-')
			attribute.minus = 1;
		else if (*f == '0')
			attribute.zero = 1;
		f++;
	}
	while (*f == '.' || ft_isdigit(*f) || *f == '*' || *f == '-')
	{
		if (*f == '.')
			f = f + my_getprecision(f, ap, &attribute);
		else if (*f == '-')
		{
			attribute.minus = 1;
			f++;
		}
		else
			f = f + my_getfield(f, ap, &attribute);
	}
	return (attribute);
}
