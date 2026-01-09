/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:47:32 by aberion           #+#    #+#             */
/*   Updated: 2025/01/30 16:19:44 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <stdio.h>

bool	assert_map_is_valid(char *file)
{
	char	*match;

	match = ft_strrchr(file, '.');
	return (!match || ft_strcmp(match, ".cub"));
}

int	quick_check(int argc, char **argv, char **env)
{
	if (env == NULL || *env == NULL)
	{
		ft_printf("Error : Missing env !\n");
		return (1);
	}
	if (argc != 2)
	{
		ft_printf("Error : Wrong number of arguments!\n");
		return (1);
	}
	if (assert_map_is_valid(argv[1]))
	{
		ft_printf("Error : Wrong map extension!\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_map_data	map_data;

	if (quick_check(argc, argv, env))
		return (1);
	map_data.fd = open(argv[1], O_RDONLY);
	if (map_data.fd == -1)
	{
		ft_putstr_fd("Error : Failed to open map\n", 2);
		return (1);
	}
	if (!parse(map_data.fd, &map_data))
	{
		close(map_data.fd);
		ft_putstr_fd("Error occured while parsing !\n", 2);
		return (1);
	}
	run(&map_data);
	close(map_data.fd);
}

void	run(t_map_data *map_data)
{
	map_data->mlx = mlx_init();
	map_data->mlx_win = mlx_new_window(map_data->mlx, WIDTH, HEIGHT, "Cub3D");
	load_textures_paths(map_data);
	mlx_hook(map_data->mlx_win, 2, 1L << 0, handle_input, map_data);
	mlx_hook(map_data->mlx_win, 17, 0L, &close_window, map_data);
	mlx_loop_hook(map_data->mlx, render_frame, map_data);
	mlx_loop(map_data->mlx);
}
