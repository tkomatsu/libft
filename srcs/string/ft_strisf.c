/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 20:58:21 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/26 21:57:49 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strisf(const char *s, int (*f)(int))
{
	int		i;
	char	*str;

	str = (char*)s;
	i = 0;
	while (str[i] && (*f)(str[i]) == 0)
		i++;
	if ((*f)(str[i]))
		return (str + i);
	return ((void*)0);
}
