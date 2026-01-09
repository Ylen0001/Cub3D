/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:59:12 by ylenoel           #+#    #+#             */
/*   Updated: 2024/03/21 16:01:27 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_str(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}

static size_t	total_len(const char *s1, const char *s2)
{
	return (ft_strlen(s1) + ft_strlen(s2));
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	total;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	total = total_len(s1, s2);
	res = malloc((total + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (s1)
	{
		copy_str(res, s1, ft_strlen(s1));
		i = ft_strlen(s1);
	}
	if (s2)
		copy_str(res + i, s2, ft_strlen(s2));
	res[total] = '\0';
	return (res);
}
