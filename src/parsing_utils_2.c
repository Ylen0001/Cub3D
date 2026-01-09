/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:24:19 by ylenoel           #+#    #+#             */
/*   Updated: 2025/01/30 16:56:45 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../minilibx/mlx.h"
#define AND &&
#define OR ||

bool	is_zeroorone(char c)
{
	return (c == '0' || c == '1');
}

bool	is_direction(char c)
{
	return (c == 'N' || c == 'E' || c == 'S' || c == 'W');
}

bool	is_validchar(char c)
{
	return (is_zeroorone(c) || is_direction(c));
}

bool	is_validchar_2(char c)
{
	return (is_zeroorone(c) || is_direction(c) || c == ' ');
}

t_directions	get_direction(char *str)
{
	if (!str OR ft_strlen(str) < 3)
		return (D_INVALID);
	if (*str == 'N' AND * (str + 1) == 'O' AND is_whitespace(*(str + 2)))
		return (NORTH);
	if (*str == 'W' AND * (str + 1) == 'E' AND is_whitespace(*(str + 2)))
		return (WEST);
	if (*str == 'E' AND * (str + 1) == 'A' AND is_whitespace(*(str + 2)))
		return (EAST);
	if (*str == 'S' AND * (str + 1) == 'O' AND is_whitespace(*(str + 2)))
		return (SOUTH);
	return (D_INVALID);
}
