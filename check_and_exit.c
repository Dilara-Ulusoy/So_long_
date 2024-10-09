/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakcakoc <dakcakoc@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:20:22 by dakcakoc          #+#    #+#             */
/*   Updated: 2024/09/06 11:48:18 by dakcakoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_if_map_is_enclosed(t_game *game)
{
	if (!is_map_enclosed_by_walls(game))
	{
		free_game_map(game);
		exit(1);
	}
}

void	check_map_exists(t_game *game)
{
	if (!game->map || game->map_height <= 0 || game->map_width <= 0)
	{
		ft_putstr("Error: No map provided or invalid map dimensions.\n");
		exit(1);
	}
}

void	check_ber_extension(const char *filename)
{
	const char	*ber;

	ber = ft_strrchr(filename, '.');
	if (!ber || ft_strncmp(ber, ".ber", 4) != 0)
	{
		ft_putstr("Error: Invalid file extension. Provide a .ber file.\n");
		exit(1);
	}
}
