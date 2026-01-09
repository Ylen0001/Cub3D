/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:22:10 by aberion           #+#    #+#             */
/*   Updated: 2025/01/31 15:12:48 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

bool	is_header_ok(char **header, t_map_data *map_data)
{
	size_t	i;
	bool	ok[2][4];

	ft_memset(ok, 0, sizeof(ok));
	i = 0;
	while (header[i])
	{
		if (!process_direction(header[i], map_data, ok[0])
			&& !process_color(header[i], map_data, ok[1])
			&& !is_empty(header[i]))
		{
			ft_putstr_fd("Something dosen't feel right with this :\n", 2);
			ft_putstr_fd(header[i], 2);
			ft_putstr_fd("\n", 2);
			return (false);
		}
		i++;
	}
	return (true);
}

int	is_map_ok(char **splitted_map, t_map_data *map_data)
{
	int		i;
	int		j;
	t_parse	*parse;

	map_data->trigger_error = 0;
	parse = &map_data->parse;
	parse->map_len = ft_lenlen(splitted_map);
	parse->found_pos = false;
	i = 0;
	j = 0;
	if (sub_is_map_ok(splitted_map, map_data, &i, &j) <= 0)
	{
		if (!parse->found_pos || map_data->trigger_error)
			ft_putstr_fd("Your map is poorly designed...\n", 2);
		return (false);
	}
	if (!parse->found_pos)
		ft_putstr_fd("To play this game, you need a player.\n", 2);
	return (parse->found_pos);
}

char	**dup_tab(char **tab)
{
	size_t	i;
	size_t	j;
	char	**dup;

	i = 0;
	j = 0;
	while (tab[i])
		i++;
	dup = ft_calloc(i + 1, sizeof(char *));
	while (j < i)
	{
		dup[j] = ft_strdup(tab[j]);
		j++;
	}
	return (dup);
}

void	init_savior(t_map_data *map_data)
{
	map_data->textures_paths[0] = NULL;
	map_data->textures_paths[1] = NULL;
	map_data->textures_paths[2] = NULL;
	map_data->textures_paths[3] = NULL;
}

bool	parse(int fd, t_map_data *map_data)
{
	char	*map;
	char	**header;
	char	**splitted_map;

	init_savior(map_data);
	map = read_whole_map(fd);
	splitted_map = split_map(map);
	map_data->ref_map = splitted_map;
	header = get_header(&splitted_map);
	if (!is_header_ok(header, map_data) || is_map_ok(splitted_map,
			map_data) <= 0)
	{
		free_before_exit(map_data);
		free(map);
		free(header);
		return (false);
	}
	map_data->map = splitted_map;
	map_data->plane_view = (t_vect2){.x = 0, .y = 0.66};
	free(header);
	free(map);
	return (true);
}
