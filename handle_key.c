/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakcakoc <dakcakoc@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:26:14 by dakcakoc          #+#    #+#             */
/*   Updated: 2024/10/04 15:41:35 by dakcakoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_CODE_ESC)
	{
		mlx_destroy_window(game->mlx_ptr, game->win);
		exit(0);
	}
	else
		handle_movement(keycode, game);
	render_map(game);
	return (0);
}

void	handle_movement(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == KEY_CODE_W || keycode == KEY_CODE_UP)
		new_y -= 1;
	else if (keycode == KEY_CODE_A || keycode == KEY_CODE_LEFT)
		new_x -= 1;
	else if (keycode == KEY_CODE_S || keycode == KEY_CODE_DOWN)
		new_y += 1;
	else if (keycode == KEY_CODE_D || keycode == KEY_CODE_RIGHT)
		new_x += 1;
	check_and_update_player_movement(game, new_x, new_y);
	render_player_view_to_direction(game, keycode);
}

void	check_and_update_player_movement(t_game *game, int new_x, int new_y)
{
	char	tile;

	if (new_x >= 0 && new_x < game->map_width
		&& new_y >= 0 && new_y < game->map_height)
	{
		tile = game->map[new_y][new_x];
		if (tile == '1')
			return ;
		if (tile == 'C')
			game->collectibles--;
		else if (tile == 'E' && game->collectibles == 0)
		{
			handle_exit(game);
		}
		ft_printf("Move: %d\n", game->move_count);
		game->move_count++;
		update_player_position(game, new_x, new_y);
	}
}

void	update_player_position(t_game *game, int new_x, int new_y)
{
	if (game->map[game->player_y][game->player_x] != 'E')
	{
		game->map[game->player_y][game->player_x] = '0';
	}
	if (game->map[new_y][new_x] != 'E' || game->collectibles == 0)
	{
		game->map[new_y][new_x] = 'P';
	}
	game->player_x = new_x;
	game->player_y = new_y;
}

void	render_player_view_to_direction(t_game *game, int direction)
{
	if (direction == KEY_CODE_UP || direction == KEY_CODE_W)
		game->img.player_current_sprite = game->img.player_img_2;
	else if (direction == KEY_CODE_DOWN || direction == KEY_CODE_S)
		game->img.player_current_sprite = game->img.player_img_5;
	else if (direction == KEY_CODE_LEFT || direction == KEY_CODE_A)
		game->img.player_current_sprite = game->img.player_img_3;
	else if (direction == KEY_CODE_RIGHT || direction == KEY_CODE_D)
		game->img.player_current_sprite = game->img.player_img_4;
}
