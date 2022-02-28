/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhamlac <lkhamlac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:48:28 by mmhaya            #+#    #+#             */
/*   Updated: 2022/02/28 16:47:56 by mmhaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parsing(int ac, char **av, t_game *game)
{
	int	i;

	if (ac != 2 || check_arg(av[1]))
	{
		write(2, "error args\n", 11);
		exit(1);
	}
	game->map.fd = open(av[1], O_RDONLY);
	if (game->map.fd < 0 || read(game->map.fd, 0, 0) == -1)
	{
		write(2, "error file\n", 11);
		exit(1);
	}
	i = parsing_arg(game);
	if (i)
	{
		if (i == 1)
			free_all(game);
		write(2, "error map\n", 10);
		exit(3);
	}
}

int	parsing_arg(t_game *game)
{
	game->map.map = ft_get_file(game->map.fd, 0);
	if (!(game->map.map))
		return (2);
	if (ft_strlen(game->map.map[0]) < 1)
		return (1);
	game->map.parsing = 0;
	check_e(game);
	check_p(game);
	check_c(game);
	map_lenght(game);
	check_border(game);
	check_border2(game);
	check_letters(game);
	if (game->map.e < 1 || game->map.c <= 0 || game->map.p != 1
		|| game->map.parsing == 1)
		return (1);
	return (0);
}

void	check_c(t_game *game)
{
	int	i;
	int	j;
	int	num_c;

	j = 1;
	i = 1;
	num_c = 0;
	while (game->map.map[i + 1])
	{
		while (game->map.map[i][j + 1])
		{
			if (game->map.map[i][j] == 'C')
				num_c++;
			j++;
		}
		j = 1;
		i++;
	}
	game->map.c = num_c;
}

void	check_p(t_game *game)
{
	int	i;
	int	j;
	int	num_p;

	j = 1;
	i = 1;
	num_p = 0;
	while (game->map.map[i + 1])
	{
		while (game->map.map[i][j + 1])
		{
			if (game->map.map[i][j] == 'P')
			{
				num_p++;
				game->map.pos_p.x = j;
				game->map.pos_p.y = i;
			}
			j++;
		}
		j = 1;
		i++;
	}
	game->map.p = num_p;
}

void	check_e(t_game *game)
{
	int	i;
	int	j;
	int	num_e;

	j = 1;
	i = 1;
	num_e = 0;
	while (game->map.map[i + 1])
	{
		while (game->map.map[i][j + 1])
		{
			if (game->map.map[i][j] == 'E')
				num_e++;
			j++;
		}
		j = 1;
		i++;
	}
	game->map.e = num_e;
}
