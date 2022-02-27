/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmhaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:14:04 by mmhaya            #+#    #+#             */
/*   Updated: 2022/02/25 18:33:18 by mmhaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_up(t_game *game)
{
	int	x;
	int	y;

	x = game->map.pos_p.x;
	y = game->map.pos_p.y;
	if (game->map.map[y - 1][x] == 'E' && game->map.c == 0)
		exit_game(game);
	if (check_wall(&game->map, x, y, 'u') == 1)
	{
		if (game->map.map[y - 1][x] == 'C')
			game->map.c -= 1;
		if (game->map.parsing == 1)
		{
			game->map.parsing = 0;
			game->map.map[y][x] = 'E';
		}
		else
			game->map.map[y][x] = '0';
		if (game->map.map[y - 1][x] == 'E')
			game->map.parsing = 1;
		game->map.map[y - 1][x] = 'P';
		game->map.pos_p.y = y - 1;
		print_image(game);
	}
}

void	go_right(t_game *game)
{
	int	x;
	int	y;

	x = game->map.pos_p.x;
	y = game->map.pos_p.y;
	if (game->map.map[y][x + 1] == 'E' && game->map.c == 0)
		exit_game(game);
	if (check_wall(&game->map, game->map.pos_p.x, game->map.pos_p.y, 'r') == 1)
	{
		if (game->map.map[y][x + 1] == 'C')
			game->map.c -= 1;
		if (game->map.parsing == 1)
		{
			game->map.parsing = 0;
			game->map.map[y][x] = 'E';
		}
		else
			game->map.map[y][x] = '0';
		if (game->map.map[y][x + 1] == 'E')
			game->map.parsing = 1;
		game->map.map[y][x + 1] = 'P';
		game->map.pos_p.x = x + 1;
		print_image(game);
	}
}

void	go_down(t_game *game)
{
	int	x;
	int	y;

	x = game->map.pos_p.x;
	y = game->map.pos_p.y;
	if (game->map.map[y + 1][x] == 'E' && game->map.c == 0)
		exit_game(game);
	if (check_wall(&game->map, x, y, 'd') == 1)
	{
		if (game->map.map[y + 1][x] == 'C')
			game->map.c -= 1;
		if (game->map.parsing == 1)
		{
			game->map.parsing = 0;
			game->map.map[y][x] = 'E';
		}
		else
			game->map.map[y][x] = '0';
		if (game->map.map[y + 1][x] == 'E')
			game->map.parsing = 1;
		game->map.map[y + 1][x] = 'P';
		game->map.pos_p.y = y + 1;
		print_image(game);
	}
}

void	go_left(t_game *game)
{
	int	x;
	int	y;

	x = game->map.pos_p.x;
	y = game->map.pos_p.y;
	if (game->map.map[y][x - 1] == 'E' && game->map.c == 0)
		exit_game(game);
	if (check_wall(&game->map, x, y, 'l') == 1)
	{
		if (game->map.map[y][x - 1] == 'C')
			game->map.c -= 1;
		if (game->map.parsing == 1)
		{
			game->map.parsing = 0;
			game->map.map[y][x] = 'E';
		}
		else
			game->map.map[y][x] = '0';
		if (game->map.map[y][x - 1] == 'E')
			game->map.parsing = 1;
		game->map.map[y][x - 1] = 'P';
		game->map.pos_p.x = x - 1;
		print_image(game);
	}
}
