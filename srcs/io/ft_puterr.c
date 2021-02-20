/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 15:25:02 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/20 09:23:10 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puterr(char *str, int errno)
{
	ft_putstr_fd(str, STDERR);
	ft_putstr_fd(": ", STDERR);
	ft_putstr_fd(strerror(errno), STDERR);
	return (1);
}
