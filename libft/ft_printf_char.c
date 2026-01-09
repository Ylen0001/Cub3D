/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:56:55 by ylenoel           #+#    #+#             */
/*   Updated: 2024/01/12 08:06:03 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(va_list params, size_t *i)
{
	char	c;

	(*i) += 2;
	c = va_arg(params, int);
	return (ft_putchar_count(c, 1));
}
