/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:03:36 by ylenoel           #+#    #+#             */
/*   Updated: 2023/11/14 13:25:49 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*buffer;
	size_t			i;

	i = 0;
	if (size == 0)
		return (malloc(0));
	if (nmemb <= 0 && size <= 0)
		return (NULL);
	if (nmemb > (SIZE_MAX / size))
		return (NULL);
	buffer = malloc(nmemb * size);
	if (!buffer)
		return (NULL);
	while (i < nmemb * size)
	{
		buffer[i] = 0;
		i++;
	}
	return ((void *)buffer);
}
