/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:56:38 by aberion           #+#    #+#             */
/*   Updated: 2025/01/29 18:12:43 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <unistd.h>

void	free_before_exit(t_map_data *map_data)
{
	size_t	i;

	i = 0;
	while (map_data && map_data->ref_map[i] != NULL)
		free(map_data->ref_map[i++]);
	free(map_data->ref_map);
	i = 0;
	while (i < 4)
	{
		if (map_data->textures_paths[i])
			free(map_data->textures_paths[i]);
		i++;
	}
	close(map_data->fd);
}
