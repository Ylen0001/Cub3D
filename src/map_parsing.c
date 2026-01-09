/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:55:27 by ylenoel           #+#    #+#             */
/*   Updated: 2025/01/31 15:10:02 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

void	is_map_ok_2(char **splitted_map, t_map_data *map_data, int *i, int *j)
{
	t_parse	*parse;

	parse = &map_data->parse;
	if (*i != 0)
		parse->len_line_up = ft_strlen(splitted_map[*i - 1]);
	else
		parse->len_line_up = -1;
	if (*i < (parse->map_len - 1))
		parse->len_line_down = ft_strlen(splitted_map[*i + 1]);
	else
		parse->len_line_down = -1;
	parse->len_line_current = ft_strlen(splitted_map[*i]);
	*j = 0;
}

int	is_map_ok_3(char **splitted_map, t_map_data *map_data, int *i, int *j)
{
	t_parse	*parse;

	parse = &map_data->parse;
	if (!is_validchar_2(splitted_map[*i][*j]))
	{
		map_data->trigger_error = 1;
		return (-1);
	}
	if (is_direction(splitted_map[*i][*j]))
	{
		if (multiplayer_detection(map_data) == -1)
			return (-1);
		map_data->player.position = (t_vect2){.x = *j + 0.5, .y = *i + 0.5};
		if (splitted_map[*i][*j] == 'N')
			map_data->player.direction = (t_vect2){.x = 0, .y = -1};
		if (splitted_map[*i][*j] == 'S')
			map_data->player.direction = (t_vect2){.x = 0, .y = 1};
		if (splitted_map[*i][*j] == 'E')
			map_data->player.direction = (t_vect2){.x = 1, .y = 0};
		if (splitted_map[*i][*j] == 'W')
			map_data->player.direction = (t_vect2){.x = -1, .y = 0};
		parse->found_pos = true;
	}
	return (1);
}

int	is_map_ok_4(char **splitted_map, t_map_data *map_data, int *i, int *j)
{
	t_parse	*parse;

	parse = &map_data->parse;
	if (parse->len_line_down == -1 || parse->len_line_up == -1 || *j == 0
		|| (size_t)(*j) == ft_strlen(splitted_map[*i]))
	{
		return (-1);
	}
	if (parse->len_line_up != -1 && *j + 1 > parse->len_line_up)
		return (-1);
	if (parse->len_line_down != -1 && *j + 1 > parse->len_line_down)
		return (-1);
	if (*j + 1 > parse->len_line_current)
		return (-1);
	if (parse->len_line_up != -1 && (!is_validchar_2(splitted_map[*i - 1][*j
				- 1]) || !is_validchar_2(splitted_map[*i - 1][*j])
			|| !is_validchar_2(splitted_map[*i - 1][*j + 1])))
	{
		return (-1);
	}
	return (1);
}

int	is_map_ok_5(char **splitted_map, t_map_data *map_data, int *i, int *j)
{
	t_parse	*parse;

	parse = &map_data->parse;
	if (parse->len_line_down != -1 && (!is_validchar(splitted_map[*i + 1][*j
				- 1]) || !is_validchar(splitted_map[*i + 1][*j])
			|| !is_validchar(splitted_map[*i + 1][*j + 1])))
	{
		return (-1);
	}
	if (j == 0 || !is_validchar(splitted_map[*i][*j - 1])
		|| !is_validchar(splitted_map[*i][*j + 1]))
	{
		return (-1);
	}
	return (1);
}

int	sub_is_map_ok(char **splitted_map, t_map_data *map_data, int *i, int *j)
{
	while (splitted_map[*i])
	{
		is_map_ok_2(splitted_map, map_data, i, j);
		while (splitted_map[*i][*j] == ' ')
			(*j)++;
		while (splitted_map[*i][*j])
		{
			if (is_map_ok_3(splitted_map, map_data, i, j) == -1)
				return (-1);
			if (splitted_map[*i][*j] != '1'
				&& is_validchar(splitted_map[*i][*j]))
			{
				if (is_map_ok_4(splitted_map, map_data, i, j) == -1)
					return (-1);
				if (is_map_ok_5(splitted_map, map_data, i, j) == -1)
					return (-1);
			}
			(*j)++;
		}
		(*i)++;
	}
	return (1);
}
