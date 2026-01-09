/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:26:56 by ylenoel           #+#    #+#             */
/*   Updated: 2024/01/12 08:06:08 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexnbr_len(unsigned long long nbr, char c)
{
	int	count;

	if (c == 'p' && nbr == 0)
		return (0);
	count = 0;
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 16;
		count++;
	}
	return (count);
}

static void	ft_putnbr_hex(unsigned long long nbr, char *base)
{
	if (nbr > 15)
	{
		ft_putnbr_hex((nbr / 16), base);
		ft_putchar_count(base[nbr % 16], 1);
	}
	else if (nbr <= 15)
		ft_putchar_count(base[nbr % 16], 1);
}

int	ft_printf_hex(unsigned long long nbr, size_t *i, char c)
{
	char				*hexbase;
	int					count;

	count = hexnbr_len(nbr, c);
	if (c == 'p')
	{
		if (nbr == 0)
		{
			write(1, "(nil)", 5);
			*i += 2;
			return (count += 5);
		}
		hexbase = "0123456789abcdef";
		count += ft_putchar_count('0', 1);
		count += ft_putchar_count('x', 1);
	}
	else if (c == 'X')
		hexbase = "0123456789ABCDEF";
	else
		hexbase = "0123456789abcdef";
	(*i) += 2;
	ft_putnbr_hex(nbr, hexbase);
	return (count);
}
