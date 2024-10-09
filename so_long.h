/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakcakoc <dakcakoc@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:47:35 by dakcakoc          #+#    #+#             */
/*   Updated: 2024/10/04 15:40:27 by dakcakoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>
# include "gnl/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"

# define TILE_SIZE 64
# define KEY_CODE_ESC 65307  // Escape key
# define KEY_CODE_W 119      // 'W' key
# define KEY_CODE_A 97       // 'A' key
# define KEY_CODE_S 115      // 'S' key
# define KEY_CODE_D 100      // 'D' key
# define KEY_CODE_UP 65362   // Up arrow key
# define KEY_CODE_DOWN 65364 // Down arrow key
# define KEY_CODE_LEFT 65361 // Left arrow key
# define KEY_CODE_RIGHT 65363 // Right arrow key

typedef struct s_img
{
	void	*wall_img;
	void	*floor_img;
	void	*collectible_img;
	void	*exit_img;
	void	*player_img_1;
	void	*player_img_2;
	void	*player_img_3;
	void	*player_img_4;
	void	*player_img_5;
	void	*player_current_sprite;
}				t_img;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		window_width;
	int		window_height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		player_count;
	int		exit_count;
	int		collectible_count;
	int		move_count;
	int		coins_collected;
	bool	exit_reached;
	t_img	img;
}				t_game;

void	load_images(t_game *game);
void	validate_images(t_game *game);

void	load_map(t_game *game, char *filename);
void	initialize_map_dimensions(int fd, t_game *game);
void	allocate_map_memory(t_game *game);
void	read_map_data(int fd, t_game *game);
void	free_game_map(t_game *game);
void	free_allocated_memory(char **copy, int count);

void	render_map(t_game *game);
void	put_image(t_game *game, void *img, int x, int y);
void	render_tile(t_game *game, char tile, int x, int y);

int		handle_key_press(int keycode, t_game *game);
void	handle_movement(int keycode, t_game *game);
void	check_and_update_player_movement(t_game *game, int new_x, int new_y);
void	handle_exit(t_game *game);
void	update_player_position(t_game *game, int new_x, int new_y);

void	initialize_player_position(t_game *game);
void	initialize_collectibles(t_game *game);
void	initialize_moves(t_game *game);
void	setup_window(t_game *game);
void	check_ber_extension(const char *filename);
int		is_map_enclosed_by_walls(t_game *game);
void	check_if_map_is_enclosed(t_game *game);

void	count_elements(t_game *game);
void	validate_counts(t_game *game);
void	check_map_validity(t_game *game);
void	render_player_view_to_direction(t_game *game, int direction);
void	ft_putstr(char *str);

bool	flood_fill(t_game *game, char **map_copy, int x, int y);
void	check_player_can_reach_exit(t_game *game);
char	**copy_map(t_game *game);
void	check_map_exists(t_game *game);
void	init_player_collectibles_moves(t_game *game);
void	check_map_dimensions(t_game *game);

void	find_player_position(t_game *game, int *player_x, int *player_y);
int		close_window(t_game *game);
void	free_map_copy(char **map_copy, int map_height);
void	cleanup_images(t_game *game);
void	validate_map_tiles(t_game *game);
void	cleanup(t_game *game);

#endif
