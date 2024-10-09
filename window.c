/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakcakoc <dakcakoc@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:06:45 by dakcakoc          #+#    #+#             */
/*   Updated: 2024/10/04 14:55:45 by dakcakoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setup_window(t_game *game)
{
	game->window_width = game->map_width * TILE_SIZE;
	game->window_height = game->map_height * TILE_SIZE;
}

int	close_window(t_game *game)
{
	cleanup(game);
	exit(0);
	return (0);
}

void	check_map_dimensions(t_game *game)
{
	if (game->map_height >= 100 || game->map_width >= 100)
	{
		ft_putstr("Error: Map dimensions is too big.\n");
		exit(1);
	}
}

void	cleanup_images(t_game *game)
{
	if (game->img.player_img_1)
		mlx_destroy_image(game->mlx_ptr, game->img.player_img_1);
	if (game->img.player_img_2)
		mlx_destroy_image(game->mlx_ptr, game->img.player_img_2);
	if (game->img.player_img_3)
		mlx_destroy_image(game->mlx_ptr, game->img.player_img_3);
	if (game->img.player_img_4)
		mlx_destroy_image(game->mlx_ptr, game->img.player_img_4);
	if (game->img.player_img_5)
		mlx_destroy_image(game->mlx_ptr, game->img.player_img_5);
	if (game->img.exit_img)
		mlx_destroy_image(game->mlx_ptr, game->img.exit_img);
	if (game->img.collectible_img)
		mlx_destroy_image(game->mlx_ptr, game->img.collectible_img);
	if (game->img.wall_img)
		mlx_destroy_image(game->mlx_ptr, game->img.wall_img);
	if (game->img.floor_img)
		mlx_destroy_image(game->mlx_ptr, game->img.floor_img);
}
