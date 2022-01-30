/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmhaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:31:12 by mmhaya            #+#    #+#             */
/*   Updated: 2022/01/25 17:29:48 by mmhaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] != '1')
			return (1);
		i++;
	}
	return (i);
}

int	check_c(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == 'c')
			return (1);
		i++;
	}
	return (0);
}

int	check_e(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == 'e')
			return (1);
		i++;
	}
	return (0);
}

int	check_p(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == 'p')
			return (1);
		i++;
	}
	return (0);
}
