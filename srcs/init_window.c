/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhamlac <lkhamlac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:07:51 by mmhaya            #+#    #+#             */
/*   Updated: 2022/02/28 16:41:17 by mmhaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 119 || keycode == 65362)
		go_up(game);
	if (keycode == 115 || keycode == 65364)
		go_down(game);
	if (keycode == 97 || keycode == 65361)
		go_left(game);
	if (keycode == 100 || keycode == 65363)
		go_right(game);
	if (keycode == 65307)
		exit_game(game);
	return (1);
}

int	exit_game(t_game *game)
{
	if (game->assets.player.img)
		mlx_destroy_image(game->window.mlx, game->assets.player.img);
	if (game->assets.floor.img)
		mlx_destroy_image(game->window.mlx, game->assets.floor.img);
	if (game->assets.wall.img)
		mlx_destroy_image(game->window.mlx, game->assets.wall.img);
	if (game->assets.collec.img)
		mlx_destroy_image(game->window.mlx, game->assets.collec.img);
	if (game->assets.exit.img)
		mlx_destroy_image(game->window.mlx, game->assets.exit.img);
	if (game->window.mlx_win)
		mlx_destroy_window(game->window.mlx, game->window.mlx_win);
	if (game->window.mlx)
	{
		mlx_destroy_display(game->window.mlx);
		free(game->window.mlx);
	}
	free_all(game);
	exit(1);
	return (0);
}

void	init_struct(t_game *game)
{
	game->assets.player.img = NULL;
	game->assets.floor.img = NULL;
	game->assets.exit.img = NULL;
	game->assets.wall.img = NULL;
	game->assets.collec.img = NULL;
	game->window.mlx = NULL;
	game->window.mlx_win = NULL;
}
