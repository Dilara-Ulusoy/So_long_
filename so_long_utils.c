/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakcakoc <dakcakoc@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:53:48 by dakcakoc          #+#    #+#             */
/*   Updated: 2024/10/04 15:38:51 by dakcakoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	free_game_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i])
			free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	free_allocated_memory(char **copy, int count)
{
	int	j;

	j = 0;
	while (j < count)
	{
		free(copy[j]);
		j++;
	}
	free(copy);
	ft_putstr("Error: Memory allocation failed.");
}

void	handle_exit(t_game *game)
{
	if (game->collectibles == 0)
	{
		cleanup(game);
		exit(0);
	}
}

void	allocate_map_memory(t_game *game)
{
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
	{
		ft_putstr("Error: Memory allocation failed.");
		exit(1);
	}
}
