/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylenoel <ylenoel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:55:51 by aberion           #+#    #+#             */
/*   Updated: 2025/01/30 16:54:43 by ylenoel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/ft_printf.h"
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>

# define WIDTH 1024
# define HEIGHT 1024
# define FOV 66 // Field of view (Champ de vision)
# define PI 3.14159265359
# define BUFFER_SIZE 100
# define MOVE_SPEED 0.25
# define ROTATION_SPEED 0.1
# define KEY_W 119 // W
# define KEY_A 97  // A
# define KEY_S 115 // S
# define KEY_D 100 // D

# define ARROW_UP 65362    // haut
# define ARROW_DOWN 65364  // bas
# define ARROW_LEFT 65361  // gauche
# define ARROW_RIGHT 65363 // droite

# define ESC_KEY 65307

typedef enum s_directions
{
	NORTH,
	EAST,
	WEST,
	SOUTH,
	D_INVALID,
}				t_directions;

typedef enum s_map_colors
{
	FLOOR,
	CEILING,
	C_INVALID,
}				t_map_colors;

typedef struct s_vect2
{
	float		x;
	float		y;
}				t_vect2;

// Structure représentant les rayons du joueur
typedef struct s_ray
{
	float		x;
	float		y;
	float		angle;
	float		distance;
	t_vect2		hit_point;
	t_vect2		ray_dir;
	int			side;
	int			face;
	int			step_x;
	int			step_y;
	t_vect2		side_dist;
	int			map_x;
	int			map_y;
}				t_ray;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			*addr_int;
	int			width;
	int			height;
	int			bpp;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_player
{
	t_vect2		direction;
	t_vect2		position;
}				t_player;

typedef struct s_texture
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_texture;

typedef struct s_angle
{
	float		player_angle;
	float		fov;
	float		angle_increment;
	float		start_angle;
	float		current_angle;
	float		distance;
	int			line_height;
}				t_angle;

typedef struct s_parse
{
	int			map_len;
	int			len_line_up;
	int			len_line_down;
	int			len_line_current;
	bool		found_pos;
	size_t		comma_count;
	int32_t		ret;
	int			composant;
	char		*comma;
}				t_parse;

// Penser à free dans le destructor (ref_map)
typedef struct s_map_data
{
	int			fd;
	t_parse		parse;
	char		**ref_map;
	char		*textures_paths[4];
	t_data		textures[4];
	t_data		img;
	int32_t		floor_and_ceiling[2];
	t_player	player;
	t_ray		rays;
	char		**map;
	t_vect2		plane_view;
	void		*mlx;
	void		*mlx_win;
	float		plane_x;
	float		plane_y;
	int			floored_x;
	int			floored_y;
	float		coef;
	float		ray_start_y;
	float		ray_end_y;
	t_angle		angle;
	int			wall_height;
	float		scale;
	int			color;
	int			trigger_error;
}				t_map_data;

typedef struct s_rgb_color
{
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
}				t_rgb_color;

// PARSING //

bool			is_validchar_2(char c);
bool			parse(int fd, t_map_data *map_data);
bool			is_id(char c);
bool			is_whitespace(char c);
bool			is_empty(char *line);
void			*ft_realloc(void *ptr, size_t capacity, size_t size,
					size_t elemSize);
t_map_colors	get_color(char c);
t_directions	get_direction(char *str);
t_rgb_color		get_rgb(int32_t color);
size_t			ft_lenlen(char **tab);
bool			is_validchar(char c);
bool			is_direction(char c);
char			*read_whole_map(int fd);
char			**split_map(char *map);
char			**get_header(char ***splitted);
int				sub_is_map_ok(char **splitted_map, t_map_data *map_data, int *i,
					int *j);
void			is_map_ok_2(char **splitted_map, t_map_data *map_data, int *i,
					int *j);
int				is_map_ok_3(char **splitted_map, t_map_data *map_data, int *i,
					int *j);
int				is_map_ok_4(char **splitted_map, t_map_data *map_data, int *i,
					int *j);
int				is_map_ok_5(char **splitted_map, t_map_data *map_data, int *i,
					int *j);
int				parse_component(t_parse *parse, char **line);
int				validate_final_component(char **line);
int				validate_line_until_comma(char **line, char *comma);
int32_t			handle_comma_separated_values(t_parse *parse, char *line);
int32_t			parse_int(t_map_data *map_data, char *line);
bool			process_color(char *header_line, t_map_data *map_data,
					bool *ok_colors);
bool			process_direction(char *header_line, t_map_data *map_data,
					bool *ok_directions);
bool			is_header_ok(char **header, t_map_data *map_data);
int				multiplayer_detection(t_map_data *map_data);

// EXEC //

void			run(t_map_data *map_data);
float			raycasting(t_map_data *map_data, float ray_angle);
int				handle_input(int keycode, t_map_data *map_data);
void			load_textures_paths(t_map_data *map_data);
void			handle_key_moves_ad(t_map_data *map_data, float *new_x,
					float *new_y, int keycode);
void			handle_key_moves_ws(t_map_data *map_data, float *new_x,
					float *new_y, int keycode);
int				load_all_textures(t_map_data *map_data);
char			*getDirectionStr(t_directions i);
void			printMapDatas(t_map_data *map_data);
void			setting_rays_face(t_map_data *map_data, float *coef_coord);
void			raycasting_walls_drawing(t_map_data *map_data, t_data *img);
void			draw_wall(t_data *img, int x, t_map_data *map_data);
void			calculus_pre_drawing(t_map_data *map_data, float coef_coord,
					int texture_height);
void			draw_wall_2(t_map_data *map_data, int x, int text_height,
					int text_width);
int				close_window(t_map_data *map_data);
void			draw_floor_ceiling(t_data *img, t_map_data *map_data);
int				render_frame(t_map_data *map_data);
void			free_before_exit(t_map_data *map_data);
char			**dup_tab(char **tab);

#endif