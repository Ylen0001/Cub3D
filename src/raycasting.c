/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberion <aberion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:05:14 by aberion           #+#    #+#             */
/*   Updated: 2025/01/24 08:50:19 by aberion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <float.h>
#include <math.h>
#include <unistd.h>

void	raycasting_walls_drawing(t_map_data *map_data, t_data *img)
{
	int		i;
	t_angle	*angle;

	i = 0;
	angle = &map_data->angle;
	while (i < WIDTH)
	{
		angle->current_angle = angle->start_angle + i * angle->angle_increment;
		angle->distance = raycasting(map_data, angle->current_angle);
		angle->distance *= cos(angle->current_angle - angle->player_angle);
		angle->line_height = (int)(HEIGHT / angle->distance);
		if (angle->line_height < 0)
		{
			angle->line_height = 64 * 64;
		}
		map_data->ray_start_y = (HEIGHT - angle->line_height) / 2;
		map_data->ray_end_y = map_data->ray_start_y
			+ map_data->angle.line_height;
		draw_wall(img, i, map_data);
		i++;
	}
}

void	initialize_raycasting_data(t_map_data *map_data, float ray_angle,
		float *deltaDistX, float *deltaDistY)
{
	t_ray	*ray;

	ray = &map_data->rays;
	ray->map_x = (int)map_data->player.position.x;
	ray->map_y = (int)map_data->player.position.y;
	ray->angle = ray_angle;
	ray->ray_dir.x = cos(ray_angle);
	ray->ray_dir.y = sin(ray_angle);
	*deltaDistX = fabs(1 / ray->ray_dir.x);
	*deltaDistY = fabs(1 / ray->ray_dir.y);
}

void	raycasting_1(t_map_data *map_data, t_ray *ray, float *deltaDistX,
		float *deltaDistY)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step_x = -1;
		ray->side_dist.x = (map_data->player.position.x - ray->map_x)
			* *deltaDistX;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist.x = (ray->map_x + 1.0 - map_data->player.position.x)
			* *deltaDistX;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step_y = -1;
		ray->side_dist.y = (map_data->player.position.y - ray->map_y)
			* *deltaDistY;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist.y = (ray->map_y + 1.0 - map_data->player.position.y)
			* *deltaDistY;
	}
}

void	raycasting_2(t_map_data *map_data, t_ray *ray, float *deltaDistX,
		float *deltaDistY)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += *deltaDistX;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += *deltaDistY;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map_data->map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

float	raycasting(t_map_data *map_data, float ray_angle)
{
	t_ray	*ray;
	float	deltadist_x;
	float	deltadist_y;

	ray = &map_data->rays;
	initialize_raycasting_data(map_data, ray_angle, &deltadist_x, &deltadist_y);
	raycasting_1(map_data, ray, &deltadist_x, &deltadist_y);
	raycasting_2(map_data, ray, &deltadist_x, &deltadist_y);
	if (ray->side == 0)
	{
		ray->distance = (ray->map_x - map_data->player.position.x + (1
					- ray->step_x) / 2) / ray->ray_dir.x;
	}
	else
		ray->distance = (ray->map_y - map_data->player.position.y + (1
					- ray->step_y) / 2) / ray->ray_dir.y;
	ray->x = map_data->player.position.x + ray->distance * ray->ray_dir.x;
	ray->y = map_data->player.position.y + ray->distance * ray->ray_dir.y;
	return (ray->distance);
}
