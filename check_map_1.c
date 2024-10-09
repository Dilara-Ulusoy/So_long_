/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakcakoc <dakcakoc@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:28:01 by dakcakoc          #+#    #+#             */
/*   Updated: 2024/10/04 15:38:58 by dakcakoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_validity(t_game *game)
{
	check_player_can_reach_exit(game);
	check_map_exists(game);
	count_elements(game);
	validate_counts(game);
	validate_map_tiles(game);
}

int	is_map_enclosed_by_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_width)
	{
		if (game->map[0][x] != '1' || game->map[game->map_height - 1][x] != '1')
		{
			ft_putstr("Map top or bottom is not fully enclosed by walls.\n");
			return (0);
		}
		x++;
	}
	y = 0;
	while (y < game->map_height)
	{
		if (game->map[y][0] != '1' || game->map[y][game->map_width - 1] != '1')
		{
			ft_putstr("Map sides are not fully enclosed by walls.\n");
			return (0);
		}
		y++;
	}
	return (1);
}

void	check_player_can_reach_exit(t_game *game)
{
	int		player_x;
	int		player_y;
	char	**map_copy;

	find_player_position(game, &player_x, &player_y);
	map_copy = copy_map(game);
	if (flood_fill(game, map_copy, player_x, player_y) == false)
	{
		ft_putstr("Error: Map is not valid. Player cannot reach the exit.\n");
		free_map_copy(map_copy, game->map_height);
		exit(1);
	}
	free_map_copy(map_copy, game->map_height);
}

void	find_player_position(t_game *game, int *player_x, int *player_y)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map_height)
	{
		y = 0;
		while (y < game->map_width)
		{
			if (game->map[x][y] == 'P')
			{
				*player_x = x;
				*player_y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

void	free_map_copy(char **map_copy, int map_height)
{
	int	i;

	i = 0;
	while (i < map_height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}
