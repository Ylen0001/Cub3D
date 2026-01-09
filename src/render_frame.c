/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:22:26 by ylenoel           #+#    #+#             */
/*   Updated: 2025/01/30 16:56:51 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <float.h>
#include <math.h>
#include <unistd.h>

int	render_frame(t_map_data *map_data)
{
	t_data	img;
	t_angle	*angle;

	angle = &map_data->angle;
	img.img = mlx_new_image(map_data->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length,
			&img.endian);
	draw_floor_ceiling(&img, map_data);
	angle->player_angle = atan2(map_data->player.direction.y,
			map_data->player.direction.x);
	angle->fov = M_PI / 3;
	angle->angle_increment = map_data->angle.fov / WIDTH;
	angle->start_angle = map_data->angle.player_angle - (map_data->angle.fov
			/ 2.0);
	raycasting_walls_drawing(map_data, &img);
	mlx_put_image_to_window(map_data->mlx, map_data->mlx_win, img.img, 0, 0);
	mlx_destroy_image(map_data->mlx, img.img);
	return (0);
}

int	multiplayer_detection(t_map_data *map_data)
{
	t_parse	*parse;

	parse = &map_data->parse;
	if (parse->found_pos)
	{
		ft_putstr_fd("This is a single player game !!\n", 2);
		return (-1);
	}
	return (1);
}

t_map_colors	get_color(char c)
{
	if (c == 'F')
		return (FLOOR);
	if (c == 'C')
		return (CEILING);
	return (C_INVALID);
}
