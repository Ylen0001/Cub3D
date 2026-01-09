/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_paths.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:14:05 by ylenoel           #+#    #+#             */
/*   Updated: 2025/01/30 16:36:00 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../minilibx/mlx.h"

void	load_textures_paths(t_map_data *map_data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		map_data->textures[i].img = mlx_xpm_file_to_image(map_data->mlx,
				map_data->textures_paths[i],
				&map_data->textures[i].width,
				&map_data->textures[i].height);
		if (map_data->textures[i].img == NULL)
		{
			printf("Error : Missing texture or invalid one : %s\n",
				map_data->textures_paths[i]);
			free_before_exit(map_data);
			exit(1);
		}
		map_data->textures[i].addr_int = (int *)mlx_get_data_addr(
				map_data->textures[i].img,
				&map_data->textures[i].bpp,
				&map_data->textures[i].line_length,
				&map_data->textures[i].endian);
		i++;
	}
}
