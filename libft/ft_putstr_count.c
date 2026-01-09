/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:20:23 by ylenoel           #+#    #+#             */
/*   Updated: 2024/01/12 08:07:58 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_count(char *s, int fd)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (s == (char *) NULL)
	{
		write(1, "(null)", 6);
		return (count += 6);
	}
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
		count++;
	}
	return (count);
}
