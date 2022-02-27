/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmhaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:45:54 by mmhaya            #+#    #+#             */
/*   Updated: 2022/02/25 18:17:26 by mmhaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	parsing(ac, av, &game);
	if (check_dim(&game))
	{
		write(2, "map is to big for the display\n", 30);
		free_all(&game);
		exit(1);
	}
	init_window(&game);
	return (0);
}
