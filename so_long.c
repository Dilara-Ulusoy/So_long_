/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakcakoc <dakcakoc@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:03:18 by dakcakoc          #+#    #+#             */
/*   Updated: 2024/10/04 15:33:01 by dakcakoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cleanup(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx_ptr, game->win);
	cleanup_images(game);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	free_game_map(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.exit_reached = false;
	game.coins_collected = 0;
	if (argc != 2)
	{
		ft_putstr("Usage: ./so_long <map_file>\n");
		return (1);
	}
	game.mlx_ptr = mlx_init();
	load_map(&game, argv[1]);
	check_if_map_is_enclosed(&game);
	check_map_exists(&game);
	init_player_collectibles_moves(&game);
	check_map_validity(&game);
	setup_window(&game);
	game.win = mlx_new_window(game.mlx_ptr,
			game.window_width, game.window_height, "SO_LONG");
	load_images(&game);
	mlx_key_hook(game.win, handle_key_press, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	render_map(&game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
