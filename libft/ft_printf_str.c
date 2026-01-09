/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:18:48 by ylenoel           #+#    #+#             */
/*   Updated: 2024/01/12 08:06:21 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_str(va_list params, size_t *i)
{
	char	*str;

	(*i) += 2;
	str = va_arg(params, char *);
	return (ft_putstr_count(str, 1));
}
