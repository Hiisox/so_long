/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmhaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:31:12 by mmhaya            #+#    #+#             */
/*   Updated: 2022/01/25 17:29:48 by mmhaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parsing_map(char **av)
{
	int		fd;
	int		len;
	char	*str;
	t_map	map;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (1);
//	printf("lol\n");
	str = get_next_line(fd);
//	printf("%s", str);
	len = check_wall(str);
//	printf("%d\n", len);
	if (len < 3)
		return (close(fd), 1);
//	printf("lol\n");
	map.e = 0;
	map.c = 0;
	map.p = 0;
	if (parsing_map2(fd, len, str, map) == 1)
		return (close(fd), 1);
	close(fd);
	return (0);
}

int	parsing_map2(int fd, int len, char *str, t_map map)
{
	char	*str2;
	int		len2;

	while (str)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		str2 = str;
		len2 = ft_strlen_map(str);
//		printf("%d\n", len);
//		printf("%d\n", len2);
		if (len2 != len)
			return (1);
		if (check_line(str, len) == 1)
			return (1);
		map.c += check_c(str);
		map.e += check_e(str);
		map.p += check_p(str);
	}
	if (map.c == 0 || map.e == 0 || map.p != 1 || check_wall(str2) == 1)
		return (1);
	return (0);
}

int	check_line(char *str, int len)
{
	int	i;

	i = 0;
	if (str[i] != '1' || str[len - 1] != '1')
		return (1);
	while (str[i] != '\n')
	{
		if (str[i] != '0' && str[i] != 'p' && str[i] != '1' && str[i] != 'e' && str[i] != 'c')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen_map(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}
