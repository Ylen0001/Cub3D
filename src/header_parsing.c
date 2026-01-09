/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:49:01 by ylenoel           #+#    #+#             */
/*   Updated: 2025/01/29 18:07:21 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

bool	process_color(char *header_line, t_map_data *map_data, bool *ok_colors)
{
	t_map_colors	color;

	color = get_color(*header_line);
	if (color == C_INVALID)
		return (false);
	if (ok_colors[color])
		return (false);
	ok_colors[color] = true;
	map_data->floor_and_ceiling[color] = parse_int(map_data, header_line);
	if (map_data->floor_and_ceiling[color] < 0)
		return (false);
	return (true);
}

bool	process_direction(char *header_line, t_map_data *map_data,
		bool *ok_directions)
{
	t_directions	direction;

	direction = get_direction(header_line);
	if (direction == D_INVALID)
		return (false);
	if (ok_directions[direction])
		return (false);
	ok_directions[direction] = true;
	if (!ft_strchr(header_line, '.'))
		return (false);
	map_data->textures_paths[direction] = ft_strdup(ft_strchr(header_line,
				'.'));
	return (true);
}
