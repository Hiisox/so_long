/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmhaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:48:28 by mmhaya            #+#    #+#             */
/*   Updated: 2022/02/24 16:39:32 by mmhaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_border2(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = game->map.x - 1;
	while (game->map.map[i])
	{
		if (game->map.map[i][0] != '1' || game->map.map[i][j] != '1')
			game->map.parsing = 1;
		i++;
	}
}

void	check_border(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (game->map.map[i])
		i++;
	i--;
	while (game->map.map[i][j])
	{
		if (game->map.map[i][j] != '1')
			game->map.parsing = 1;
		j++;
	}
	j = 0;
	while (game->map.map[0][j])
	{
		if (game->map.map[0][j] != '1')
			game->map.parsing = 1;
		j++;
	}
}

void	map_lenght(t_game *game)
{
	int	y;
	int	k;
	int	x;

	y = 0;
	k = 0;
	while (game->map.map[y][k])
		k++;
	x = k;
	while (game->map.map[y])
	{
		k = 0;
		while (game->map.map[y][k])
			k++;
		if (k != x)
			game->map.parsing = 1;
		y++;
	}
	game->map.x = x;
	game->map.y = y;
}

void	check_letters(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map.map[i])
	{
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] != 'E' && game->map.map[i][j] != 'P'
				&& game->map.map[i][j] != 'C' && game->map.map[i][j] != '1'
				&& game->map.map[i][j] != '0')
				game->map.parsing = 1;
			j++;
		}
		j = 0;
		i++;
	}
}

int	check_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (ft_strncmp(&str[i - 4], ".ber", 4))
		return (1);
	return (0);
}
