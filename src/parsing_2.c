/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:43:41 by aberion           #+#    #+#             */
/*   Updated: 2025/01/31 14:58:31 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*read_whole_map(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*ret;
	int		bytes_read;
	size_t	ret_len;
	size_t	ret_size;

	ft_memset(buffer, 0, sizeof(buffer));
	ret_len = 0;
	ret_size = BUFFER_SIZE;
	ret = ft_calloc(BUFFER_SIZE, sizeof(char));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		if (ret_len + bytes_read >= ret_size)
		{
			ret_size *= 2;
			ret = ft_realloc(ret, ret_size, ret_len, sizeof(char));
		}
		ft_memcpy(ret + ret_len, buffer, bytes_read);
		ret_len += bytes_read;
		ft_memset(buffer, 0, BUFFER_SIZE);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (ret);
}

char	**split_map(char *map)
{
	char	**ret;
	size_t	ret_len;
	size_t	ret_size;
	char	*match;

	ret_size = 10;
	ret_len = 0;
	ret = ft_calloc(ret_size, sizeof(char *));
	while (map && *map)
	{
		if (ret_len + 1 >= ret_size)
		{
			ret_size *= 2;
			ret = ft_realloc(ret, ret_size, ret_len, sizeof(char *));
		}
		match = ft_strchr(map, '\n');
		ret[ret_len] = ft_substr(map, 0, (match - map));
		ret_len++;
		map += (match - map + (match != NULL));
	}
	ret[ret_len] = NULL;
	return (ret);
}

char	**get_header(char ***splitted)
{
	char	**ret;
	char	**splitted_map;
	size_t	ret_len;
	size_t	ret_size;

	ret_size = 10;
	ret_len = 0;
	splitted_map = *splitted;
	ret = ft_calloc(ret_size, sizeof(char *));
	while (splitted_map && *splitted_map)
	{
		if (ret_len >= ret_size)
		{
			ret_size *= 2;
			ret = ft_realloc(ret, ret_size, ret_len, sizeof(char *));
		}
		if (is_id(**splitted_map) || is_empty(*splitted_map))
			ret[ret_len++] = *splitted_map;
		else
			break ;
		splitted_map++;
	}
	*splitted = splitted_map;
	return (ret);
}
