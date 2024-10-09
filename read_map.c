/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakcakoc <dakcakoc@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:13:27 by dakcakoc          #+#    #+#             */
/*   Updated: 2024/10/04 15:32:29 by dakcakoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_map(t_game *game, char *filename)
{
	int	fd;

	check_ber_extension(filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error: Failed to open map file.");
		exit(1);
	}
	initialize_map_dimensions(fd, game);
	check_map_dimensions(game);
	allocate_map_memory(game);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error: Failed to open map file on second pass.");
		free_game_map(game);
		exit(1);
	}
	read_map_data(fd, game);
	close(fd);
}

void	read_map_data(int fd, t_game *game)
{
	char	*line;
	int		y;

	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
		{
			free(line);
			break ;
		}
		game->map[y] = line;
		y++;
	}
	game->map[y] = NULL;
}

void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr,
		game->win, img, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_tile(t_game *game, char tile, int x, int y)
{
	if (tile == '0')
		put_image(game, game->img.floor_img, x, y);
	else if (tile == '1')
		put_image(game, game->img.wall_img, x, y);
	else if (tile == 'E')
		put_image(game, game->img.exit_img, x, y);
	else if (tile == 'P')
		put_image(game, game->img.player_current_sprite, x, y);
	else if (tile == 'C')
		put_image(game, game->img.collectible_img, x, y);
	else
	{
		ft_putstr("Unknown tile detected\n");
		exit(1);
	}
}

void	render_map(t_game *game)
{
	char	tile;
	int		x;
	int		y;

	if (!game->map)
	{
		ft_putstr("Error: Map is not loaded.\n");
		return ;
	}
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			tile = game->map[y][x];
			render_tile(game, tile, x, y);
			x++;
		}
		y++;
	}
}
