/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:06:12 by ylenoel           #+#    #+#             */
/*   Updated: 2023/11/14 16:17:38 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*result;
	size_t		i;
	size_t		istart;
	size_t		s1_len;
	size_t		result_len;

	if (!s1 || !set)
		return (NULL);
	s1_len = ft_strlen(s1);
	i = 0;
	while (check_set(s1[i], set) == 1)
		i++;
	istart = i;
	while (check_set(s1[s1_len - 1], set) == 1)
		s1_len--;
	result_len = s1_len - istart;
	result = ft_substr(s1 + istart, 0, result_len);
	return (result);
}
