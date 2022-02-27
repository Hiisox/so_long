/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmhaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:13:32 by mmhaya            #+#    #+#             */
/*   Updated: 2022/02/25 19:06:39 by mmhaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall(t_map *map, int x, int y, char next)
{
	if (next == 'u')
		if (map->map[y - 1][x] == '1')
			return (0);
	if (next == 'd')
		if (map->map[y + 1][x] == '1')
			return (0);
	if (next == 'l')
		if (map->map[y][x - 1] == '1')
			return (0);
	if (next == 'r')
		if (map->map[y][x + 1] == '1')
			return (0);
	return (1);
}

void	init_window(t_game *game)
{
	int	x;
	int	y;

	x = game->map.x;
	y = game->map.y;
	game->window.count = 0;
	game->window.mlx = mlx_init();
	if (game->window.mlx == NULL)
		exit_game(game);
	game->window.mlx_win = mlx_new_window(game->window.mlx,
			x * 60, y * 60, "so_long");
	if (game->window.mlx_win == NULL)
		exit_game(game);
	init_images(game);
	print_image(game);
	if (mlx_key_hook(game->window.mlx_win, key_hook, game) == NULL)
		exit_game(game);
	if (mlx_hook(game->window.mlx_win, 17, 1L << 17, exit_game, game) == NULL)
		exit_game(game);
	if (mlx_loop(game->window.mlx) == NULL)
		exit_game(game);
}

void	init_images(t_game *game)
{
	game->assets.wall.img = mlx_xpm_file_to_image(game->window.mlx,
			WALL, &game->assets.wall.width, &game->assets.wall.height);
	if (game->assets.wall.img == NULL)
		exit_game(game);
	game->assets.player.img = mlx_xpm_file_to_image(game->window.mlx,
			PLAYER, &game->assets.player.width, &game->assets.player.height);
	if (game->assets.player.img == NULL)
		exit_game(game);
	game->assets.floor.img = mlx_xpm_file_to_image(game->window.mlx,
			FLOOR, &game->assets.floor.width, &game->assets.floor.height);
	if (game->assets.floor.img == NULL)
		exit_game(game);
	game->assets.collec.img = mlx_xpm_file_to_image(game->window.mlx,
			COLLEC, &game->assets.collec.width, &game->assets.collec.height);
	if (game->assets.collec.img == NULL)
		exit_game(game);
	game->assets.exit.img = mlx_xpm_file_to_image(game->window.mlx,
			EXIT, &game->assets.exit.width, &game->assets.exit.height);
	if (game->assets.exit.img == NULL)
		exit_game(game);
}

void	print_image(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (game->window.count > 0)
	{
		if (mlx_clear_window(game->window.mlx, game->window.mlx_win) == NULL)
			exit_game(game);	
		printf("move's count = %d\n", game->window.count);
	}
	while (game->map.map[i])
	{
		while (game->map.map[i][j])
		{
			print_image2(game, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	game->window.count += 1;
}

void	print_image2(t_game *game, int i, int j)
{
	if (game->map.map[i][j] == '0')
		if (mlx_put_image_to_window(game->window.mlx,
			game->window.mlx_win, game->assets.floor.img, j * 60, i * 60) == NULL)
			exit_game(game);
	else if (game->map.map[i][j] == '1')
		if (mlx_put_image_to_window(game->window.mlx,
			game->window.mlx_win, game->assets.wall.img, j * 60, i * 60) == NULL)
			exit_game(game);
	else if (game->map.map[i][j] == 'C')
		if (mlx_put_image_to_window(game->window.mlx,
			game->window.mlx_win, game->assets.collec.img, j * 60, i * 60) == NULL)
			exit_game(game);
	else if (game->map.map[i][j] == 'E')
		if (mlx_put_image_to_window(game->window.mlx,
			game->window.mlx_win, game->assets.exit.img, j * 60, i * 60) == NULL)
			exit_game(game);
	else if (game->map.map[i][j] == 'P')
		if (mlx_put_image_to_window(game->window.mlx,
			game->window.mlx_win, game->assets.player.img, j * 60, i * 60 == NULL))
			exit_game(game);
}
