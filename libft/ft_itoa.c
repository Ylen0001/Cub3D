/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberion <aberion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:31:39 by ylenoel           #+#    #+#             */
/*   Updated: 2024/08/21 15:57:25 by aberion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

static char	*pre_conv(int len)
{
	char	*buffer;

	buffer = malloc((len + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[0] = '0';
	return (buffer);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		n_len;
	long	nbr;
	int		i;

	nbr = n;
	n_len = int_len(nbr);
	result = pre_conv(n_len);
	if (!result)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	i = n_len - 1;
	while (nbr != 0)
	{
		result[i] = (nbr % 10) + 48;
		nbr = nbr / 10;
		i--;
	}
	if (n < 0)
		result[0] = '-';
	result[n_len] = 0;
	return (result);
}
