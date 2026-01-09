/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberion <aberion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:20:27 by aberion           #+#    #+#             */
/*   Updated: 2025/01/24 16:35:17 by aberion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	handle_moves(int keycode, t_map_data *map_data)
{
	float	dir_x;
	float	dir_y;
	float	new_x;
	float	new_y;

	dir_x = map_data->player.direction.x;
	dir_y = map_data->player.direction.y;
	map_data->plane_x = -dir_y;
	map_data->plane_y = dir_x;
	if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_D
		|| keycode == KEY_A)
	{
		if (keycode == KEY_W || keycode == KEY_S)
			handle_key_moves_ws(map_data, &new_x, &new_y, keycode);
		else if (keycode == KEY_D || keycode == KEY_A)
			handle_key_moves_ad(map_data, &new_x, &new_y, keycode);
		if (map_data->map[(int)new_y][(int)new_x] != '1')
		{
			map_data->player.position.x = new_x;
			map_data->player.position.y = new_y;
		}
	}
}

void	handle_key_moves_ws(t_map_data *map_data, float *new_x, float *new_y,
		int keycode)
{
	float	dir_x;
	float	dir_y;

	dir_x = map_data->player.direction.x;
	dir_y = map_data->player.direction.y;
	if (keycode == KEY_W)
	{
		*new_x = map_data->player.position.x + dir_x * MOVE_SPEED;
		*new_y = map_data->player.position.y + dir_y * MOVE_SPEED;
	}
	else if (keycode == KEY_S)
	{
		*new_x = map_data->player.position.x - dir_x * MOVE_SPEED;
		*new_y = map_data->player.position.y - dir_y * MOVE_SPEED;
	}
}

void	handle_key_moves_ad(t_map_data *map_data, float *new_x, float *new_y,
		int keycode)
{
	if (keycode == KEY_D)
	{
		*new_x = map_data->player.position.x + map_data->plane_x * MOVE_SPEED;
		*new_y = map_data->player.position.y + map_data->plane_y * MOVE_SPEED;
	}
	else if (keycode == KEY_A)
	{
		*new_x = map_data->player.position.x - (map_data->plane_x * MOVE_SPEED);
		*new_y = map_data->player.position.y - (map_data->plane_y * MOVE_SPEED);
	}
}

void	update_player_direction(int keycode, t_map_data *map_data)
{
	double	old_dir_x;
	double	angle;

	if (keycode == ARROW_RIGHT)
		angle = +ROTATION_SPEED;
	else
	{
		angle = -ROTATION_SPEED;
	}
	old_dir_x = map_data->player.direction.x;
	map_data->player.direction.x = map_data->player.direction.x * cos(angle)
		- map_data->player.direction.y * sin(angle);
	map_data->player.direction.y = old_dir_x * sin(angle)
		+ map_data->player.direction.y * cos(angle);
}

int	handle_input(int keycode, t_map_data *map_data)
{
	if (keycode == KEY_A || keycode == KEY_D || keycode == KEY_S
		|| keycode == KEY_W)
		handle_moves(keycode, map_data);
	if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT)
		update_player_direction(keycode, map_data);
	else if (keycode == ESC_KEY)
	{
		mlx_destroy_window(map_data->mlx, map_data->mlx_win);
		free_before_exit(map_data);
		exit(0);
	}
	return (0);
}
