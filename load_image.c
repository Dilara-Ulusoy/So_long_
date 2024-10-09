/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakcakoc <dakcakoc@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:30:08 by dakcakoc          #+#    #+#             */
/*   Updated: 2024/10/04 15:31:21 by dakcakoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int	img_width;
	int	img_height;

	game->img.player_img_1 = mlx_xpm_file_to_image(game->mlx_ptr,
			"game_images/player.xpm", &img_width, &img_height);
	game->img.player_current_sprite = game->img.player_img_1;
	game->img.player_img_2 = mlx_xpm_file_to_image(game->mlx_ptr,
			"game_images/player2.xpm", &img_width, &img_height);
	game->img.player_img_3 = mlx_xpm_file_to_image(game->mlx_ptr,
			"game_images/player3.xpm", &img_width, &img_height);
	game->img.player_img_4 = mlx_xpm_file_to_image(game->mlx_ptr,
			"game_images/player4.xpm", &img_width, &img_height);
	game->img.player_img_5 = mlx_xpm_file_to_image(game->mlx_ptr,
			"game_images/player.xpm", &img_width, &img_height);
	game->img.exit_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"game_images/exit.xpm", &img_width, &img_height);
	game->img.collectible_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"game_images/collectible.xpm", &img_width, &img_height);
	game->img.wall_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"game_images/wall.xpm", &img_width, &img_height);
	game->img.floor_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"game_images/floor.xpm", &img_width, &img_height);
	validate_images(game);
}

void	validate_images(t_game *game)
{
	if (!game->img.player_img_1 || !game->img.player_img_2
		|| !game->img.player_img_3 || !game->img.player_img_4
		|| !game->img.player_img_5
		|| !game->img.exit_img || !game->img.collectible_img
		|| !game->img.wall_img || !game->img.floor_img)
	{
		ft_putstr("Error: Failed to load images.\n");
		cleanup_images(game);
		exit(1);
	}
}

void	validate_map_tiles(t_game *game)
{
	int		x;
	int		y;
	char	tile;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			tile = game->map[y][x];
			if (tile != '0' && tile != '1'
				&& tile != 'E' && tile != 'P' && tile != 'C')
			{
				ft_putstr("Error: Invalid tile detected.\n");
				exit(1);
			}
			x++;
		}
		y++;
	}
}
