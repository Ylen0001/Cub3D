/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberion <aberion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:14:19 by ylenoel           #+#    #+#             */
/*   Updated: 2025/01/24 08:50:36 by aberion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int32_t	parse_int(t_map_data *map_data, char *line)
{
	t_parse	*parse;
	size_t	i;

	parse = &map_data->parse;
	i = 0;
	parse->comma_count = 0;
	parse->ret = 0;
	line++;
	while (is_whitespace(line[i++]))
		;
	line += (i - 1);
	return (handle_comma_separated_values(parse, line));
}

int32_t	handle_comma_separated_values(t_parse *parse, char *line)
{
	while (parse->comma_count <= 2 && line && *line)
	{
		while (is_whitespace(*line))
			line++;
		if (!ft_isdigit(*line))
			return (-2);
		if (parse_component(parse, &line) < 0)
			return (-38);
		if (parse->comma_count != 2)
		{
			if (validate_line_until_comma(&line, parse->comma) < 0)
				return (-4);
		}
		else
		{
			if (validate_final_component(&line) < 0)
				return (-21);
			line = NULL;
		}
		parse->ret |= (parse->composant <<= 8 * (2 - parse->comma_count));
		line++;
		parse->comma_count++;
	}
	return (parse->ret);
}

int	validate_line_until_comma(char **line, char *comma)
{
	while (*line != comma)
	{
		if (!ft_isdigit(**line) && !is_whitespace(**line))
			return (-1);
		(*line)++;
	}
	return (0);
}

int	validate_final_component(char **line)
{
	while (ft_isdigit(**line))
		(*line)++;
	if (!is_empty(*line))
		return (-1);
	return (0);
}

int	parse_component(t_parse *parse, char **line)
{
	parse->composant = ft_atoi(*line);
	if (parse->composant > 255 || parse->composant < 0)
		return (-1);
	parse->comma = ft_strchr(*line, ',');
	return (0);
}
