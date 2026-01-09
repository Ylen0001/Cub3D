/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:54:29 by ylenoel           #+#    #+#             */
/*   Updated: 2023/11/08 13:25:23 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// memchr fonctionne comme strchr, à une différence ;
// strchr renvoie le caractère littéral
// memchr renvoie un pointeur sur 
// l'emplacement du caractère dans la string en hexadécimal
// sinon il renvoie NULL.

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	to_find;

	to_find = (unsigned char)c;
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == to_find)
			return ((void *)str + i);
		i++;
	}
	return (NULL);
}
