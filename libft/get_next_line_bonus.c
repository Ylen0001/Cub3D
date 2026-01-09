/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:18:25 by ylenoel           #+#    #+#             */
/*   Updated: 2023/12/15 11:32:12 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*fill_line(int fd, char *left_over, char *buffer);
static char	*set_leftover(char *result);

char	*get_next_line(int fd)
{
	static char	*left_over[1024];
	char		*result;
	char		*buffer;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		free(left_over[fd]);
		left_over[fd] = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	result = fill_line(fd, left_over[fd], buffer);
	free (buffer);
	buffer = NULL;
	if (!result)
		return (NULL);
	left_over[fd] = set_leftover(result);
	return (result);
}

static char	*fill_line(int fd, char *left_over, char *buffer)
{
	ssize_t	bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(left_over), NULL);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!left_over)
			left_over = ft_calloc(1, 1);
		tmp = left_over;
		left_over = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(left_over, '\n'))
			break ;
	}
	return (left_over);
}

static char	*set_leftover(char *result)
{
	char	*left;
	int		i;

	i = 0;
	while (result[i] != '\n' && result[i] != '\0')
		i++;
	if (result[i] == 0 || result[1] == 0)
		return (NULL);
	left = ft_substr (result, i + 1, ft_strlen(result) - i);
	if (*left == 0)
	{
		free (left);
		left = NULL;
	}
	result[i + 1] = 0;
	return (left);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}
