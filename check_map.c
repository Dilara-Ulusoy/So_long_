/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakcakoc <dakcakoc@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:32:40 by dakcakoc          #+#    #+#             */
/*   Updated: 2024/09/10 11:08:51 by dakcakoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_elements(t_game *game)
{
	int	y;
	int	x;

	game->player_count = 0;
	game->exit_count = 0;
	game->collectible_count = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'P')
				game->player_count++;
			else if (game->map[y][x] == 'E')
				game->exit_count++;
			else if (game->map[y][x] == 'C')
				game->collectible_count++;
			x++;
		}
		y++;
	}
}

void	validate_counts(t_game *game)
{
	if (game->player_count != 1)
	{
		ft_putstr("Error: Player count is not exactly 1.\n");
		exit(1);
	}
	if (game->exit_count != 1)
	{
		ft_putstr("Error: Exit count is not exactly 1.\n");
		exit(1);
	}
	if (game->collectible_count < 1)
	{
		ft_putstr("Error: Collectible count is not enough.\n");
		exit(1);
	}
}

char	**copy_map(t_game *game)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (game->map_height + 1));
	if (!copy)
	{
		ft_putstr("Error: Memory allocation failed.");
		exit(1);
	}
	i = 0;
	while (i < game->map_height)
	{
		copy[i] = strdup(game->map[i]);
		if (!copy[i])
		{
			free_allocated_memory(copy, i);
		}
		i++;
	}
	copy[game->map_height] = NULL;
	return (copy);
}

bool	flood_fill(t_game *game, char **map_copy, int x, int y)
{
	if (x < 0 || x >= game->map_height || y < 0 || y >= game->map_width)
		return (false);
	if (map_copy[x][y] == '1' || map_copy[x][y] == 'V')
		return (false);
	if (map_copy[x][y] == 'E')
	{
		game->exit_reached = true;
	}
	if (map_copy[x][y] == 'C')
	{
		game->coins_collected++;
	}
	map_copy[x][y] = 'V';
	flood_fill(game, map_copy, x - 1, y);
	flood_fill(game, map_copy, x + 1, y);
	flood_fill(game, map_copy, x, y - 1);
	flood_fill(game, map_copy, x, y + 1);
	if (game->coins_collected == game->collectibles && game->exit_reached)
		return (true);
	return (false);
}
