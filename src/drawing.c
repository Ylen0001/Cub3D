/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberion <aberion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:39:33 by ylenoel           #+#    #+#             */
/*   Updated: 2025/01/24 08:51:58 by aberion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../minilibx/mlx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_wall(t_data *img, int x, t_map_data *map_data)
{
	int		texture_height;
	int		texture_width;
	float	coef_coord;

	map_data->img = *img;
	coef_coord = 0.0;
	setting_rays_face(map_data, &coef_coord);
	texture_height = map_data->textures[map_data->rays.face].height;
	texture_width = map_data->textures[map_data->rays.face].width;
	calculus_pre_drawing(map_data, coef_coord, texture_height);
	draw_wall_2(map_data, x, texture_height, texture_width);
}

void	draw_wall_2(t_map_data *map_data, int x,
	int text_height, int text_width)
{
	int		pixel;
	int		y;
	int		texture_y;
	int		texture_x;
	size_t	idx;

	y = map_data->ray_start_y;
	while (y < map_data->ray_end_y)
	{
		if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		{
			texture_y = (int)((y - map_data->ray_start_y) * map_data->scale)
				% text_height;
			if (map_data->rays.face == EAST || map_data->rays.face == SOUTH)
				texture_x = (text_width - 1 - ((int)(map_data->coef
								* text_width) % text_width));
			else
				texture_x = (int)(map_data->coef * text_width) % text_width;
			idx = (texture_y * text_width) + texture_x;
			pixel = map_data->textures[map_data->rays.face].addr_int[idx];
			map_data->color = pixel;
			my_mlx_pixel_put(&map_data->img, x, y, map_data->color);
		}
		y++;
	}
}

void	draw_floor_ceiling(t_data *img, t_map_data *map_data)
{
	int	y;
	int	x;

	y = 0;
	while (y < (HEIGHT / 2))
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(img, x, y, map_data->floor_and_ceiling[0]);
			x++;
		}
		y++;
	}
	y = HEIGHT / 2;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(img, x, y, map_data->floor_and_ceiling[1]);
			x++;
		}
		y++;
	}
}
