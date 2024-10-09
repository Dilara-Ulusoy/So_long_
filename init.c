/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakcakoc <dakcakoc@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 23:05:24 by dakcakoc          #+#    #+#             */
/*   Updated: 2024/09/06 10:55:00 by dakcakoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_map_dimensions(int fd, t_game *game)
{
	char	*line;
	int		line_length;

	game->map_height = 0;
	game->map_width = 0;
	line = get_next_line(fd);
	while (line && line[0] != '\n')
	{
		line_length = ft_strlen(line);
		if (line[line_length - 1] == '\n')
			line[--line_length] = '\0';
		if (game->map_width == 0)
			game->map_width = line_length;
		else if (line_length != game->map_width)
		{
			ft_putstr("Error: Inconsistent map width.\n");
			free(line);
			close(fd);
			exit(1);
		}
		game->map_height++;
		free(line);
		line = get_next_line(fd);
	}
}

void	initialize_player_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	ft_putstr("Error: Player not found on the map.\n");
	free_game_map(game);
	exit(1);
}

void	initialize_collectibles(t_game *game)
{
	int	y;
	int	x;

	game->collectibles = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C')
			{
				game->collectibles++;
			}
			x++;
		}
		y++;
	}
}

void	initialize_moves(t_game *game)
{
	game->move_count = 0;
}

void	init_player_collectibles_moves(t_game *game)
{
	initialize_player_position(game);
	initialize_collectibles(game);
	initialize_moves(game);
}
