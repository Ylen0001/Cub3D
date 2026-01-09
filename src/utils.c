/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberion <aberion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:41:59 by ylenoel           #+#    #+#             */
/*   Updated: 2025/01/28 14:27:52 by aberion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../minilibx/mlx.h"

void	calculus_pre_drawing(t_map_data *map_data, float coef_coord,
		int texture_height)
{
	map_data->floored_x = floor(coef_coord);
	map_data->coef = coef_coord - map_data->floored_x;
	map_data->wall_height = map_data->ray_end_y - map_data->ray_start_y;
	map_data->scale = (float)texture_height / map_data->wall_height;
}

void	setting_rays_face(t_map_data *map_data, float *coef_coord)
{
	if (map_data->rays.side == 1)
	{
		if (map_data->rays.ray_dir.y < 0)
			map_data->rays.face = NORTH;
		else
			map_data->rays.face = SOUTH;
	}
	else if (map_data->rays.side == 0)
	{
		if (map_data->rays.ray_dir.x < 0)
			map_data->rays.face = EAST;
		else
			map_data->rays.face = WEST;
	}
	if (map_data->rays.side == 1)
		*coef_coord = map_data->rays.x;
	else
		*coef_coord = map_data->rays.y;
}

int	test_key_hook(int keycode, void *param)
{
	(void)param;
	printf("Key pressed: %d\n", keycode);
	return (0);
}

int	handle_key_release(int keycode, void *param)
{
	(void)param;
	printf("Key released: %d\n", keycode);
	return (0);
}

int	close_window(t_map_data *map_data)
{
	free_before_exit(map_data);
	exit(0);
}
