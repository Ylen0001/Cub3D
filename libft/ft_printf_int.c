/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:49:42 by ylenoel           #+#    #+#             */
/*   Updated: 2024/01/12 08:06:15 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_unsigned(unsigned int nb)
{
	if (nb > 9)
	{
		ft_putnbr_unsigned(nb / 10);
	}
	ft_putchar_count(nb % 10 + '0', 1);
}

static int	nbr_len(long long int nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
		count++;
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

int	ft_printf_int(va_list params, size_t *i, int trigger)
{
	int				nbr;
	unsigned int	nb;

	(*i) += 2;
	if (trigger)
	{
		nb = va_arg(params, unsigned int);
		ft_putnbr_unsigned(nb);
		return (nbr_len(nb));
	}
	else
	{
		nbr = va_arg(params, int);
		ft_putnbr_fd(nbr, 1);
	}
	return (nbr_len(nbr));
}
