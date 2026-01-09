/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:19:23 by ylenoel           #+#    #+#             */
/*   Updated: 2024/01/12 08:06:27 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_operand(const char *txt, size_t *i, va_list params, int *count)
{
	if (txt[*i + 1] == 's')
		*count += ft_printf_str(params, i);
	else if (txt[*i + 1] == 'd' || txt[*i + 1] == 'i')
		*count += ft_printf_int(params, i, 0);
	else if (txt[*i + 1] == 'u')
		*count += ft_printf_int(params, i, 1);
	else if (txt[*i + 1] == 'c')
		*count += ft_printf_char(params, i);
	else if (txt[*i + 1] == 'p')
		*count += ft_printf_hex(va_arg(params, unsigned long long), i, 'p');
	else if (txt[*i + 1] == 'X')
		*count += ft_printf_hex(va_arg(params, unsigned int), i, 'X');
	else if (txt[*i + 1] == 'x')
		*count += ft_printf_hex(va_arg(params, unsigned int), i, 'x');
	return (*count);
}

int	ft_printf(const char *txt, ...)
{
	va_list	params;
	size_t	i;
	int		count;

	count = 0;
	i = 0;
	if (!txt)
		return (-1);
	va_start(params, txt);
	while (txt[i])
	{
		if (txt[i] == '%')
			check_operand(txt, &i, params, &count);
		if (txt[i] == '%' && txt[i + 1] == '%')
		{
			count += ft_putchar_count('%', 1);
			i += 2;
		}
		else if (txt[i] != '%' && txt[i] != '\0')
		{
			write(1, &txt[i++], 1);
			count++;
		}
	}
	return (count);
}
