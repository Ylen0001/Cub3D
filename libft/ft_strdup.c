/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:51:01 by ylenoel           #+#    #+#             */
/*   Updated: 2024/03/21 15:41:04 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	char	*result;
	size_t	i;

	s_len = ft_strlen(s);
	i = 0;
	result = malloc(sizeof(char) * (s_len + 1));
	if (!result)
		return (NULL);
	if (!s)
		return (result);
	while (i < s_len)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
