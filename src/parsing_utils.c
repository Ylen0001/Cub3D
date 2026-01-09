/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberion <aberion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:18:27 by aberion           #+#    #+#             */
/*   Updated: 2025/01/30 15:05:42 by aberion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	is_id(char c)
{
	return (c == 'N' || c == 'W' || c == 'E' || c == 'S' || c == 'F'
		|| c == 'C');
}

bool	is_whitespace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

bool	is_empty(char *line)
{
	size_t	i;

	i = 0;
	while (is_whitespace(line[i]))
		i++;
	return (line[i] == 0);
}

size_t	ft_lenlen(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	*ft_realloc(void *ptr, size_t capacity, size_t size, size_t elemSize)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (malloc(capacity));
	if (!capacity)
		return (ptr);
	new_ptr = ft_calloc(capacity, elemSize);
	ft_memcpy(new_ptr, ptr, size * elemSize);
	free(ptr);
	return (new_ptr);
}
