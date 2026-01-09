/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:37:28 by ylenoel           #+#    #+#             */
/*   Updated: 2024/10/08 13:04:13 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	unsigned char	*buffer;
// 	size_t			i;

// 	i = 0;
// 	if (size == 0)
// 		return (malloc(0));
// 	if (nmemb <= 0 && size <= 0)
// 		return (NULL);
// 	if (nmemb > (SIZE_MAX / size))
// 		return (NULL);
// 	buffer = malloc(nmemb * size);
// 	if (!buffer)
// 		return (NULL);
// 	while (i < nmemb * size)
// 	{
// 		buffer[i] = 0;
// 		i++;
// 	}
// 	return ((void *)buffer);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == (char)c)
// 		{
// 			i++;
// 			return ((char *)s + i);
// 		}	
// 		i++;
// 	}
// 	if (s[i] == (char)c)
// 		return ((char *)s + i);
// 	return (NULL);
// }

// char	*ft_strdup(const char *s)
// {
// 	size_t	s_len;
// 	char	*result;
// 	size_t	i;

// 	s_len = strlen(s);
// 	i = 0;
// 	result = malloc (sizeof(char) * (s_len + 1));
// 	if (!result)
// 		return (NULL);
// 	if (!s)
// 		return (result);
// 	while (i < s_len)
// 	{
// 		result[i] = s[i];
// 		i++;
// 	}
// 	return (result);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	char	*str;

// 	if (!s)
// 		return (NULL);
// 	if (start > strlen(s))
// 		return (ft_strdup(""));
// 	if (len > strlen(s + start))
// 		len = strlen(s + start);
// 	str = ft_calloc(len + 1, sizeof(char));
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	while (i < len)
// 	{
// 		str[i] = s[start + i];
// 		i++;
// 		str[i] = '\0';
// 	}
// 	return (str);
// }

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	res = ft_calloc((strlen(s1) + strlen(s2) + 1), sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}
