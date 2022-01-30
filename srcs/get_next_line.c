/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmhaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:02:11 by mmhaya            #+#    #+#             */
/*   Updated: 2021/12/14 14:26:17 by mmhaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_next_line(int fd)
{
	char		*buff;
	char		*str;
	static char	*save = NULL;
	int			read_value;

	read_value = 1;
	if (fd < 0)
		return (NULL);
	buff = (char *)malloc(81);
	if (!buff)
		return (NULL);
	while (read_value > 0 && !ft_strchr(save))
	{
		read_value = read(fd, buff, 80);
		if (read_value == -1)
			return (free(buff), NULL);
		buff[read_value] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	str = only_str(save);
	save = only_areturn(save);
	return (str);
}

char	*only_str(char *str)
{
	char	*str2;
	int		i;

	i = 0;
	if (!str)
		return (0);
	if (!(*str))
		return (free(str), NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	str2 = (char *)malloc(i + 1);
	if (!str2)
		return (0);
	i = -1;
	while (str[++i] && str[i] != '\n')
		str2[i] = str[i];
	str2[i] = str[i];
	if (str[i] == '\n')
		str2[++i] = '\0';
	return (str2);
}

char	*only_areturn(char *str)
{
	char	*str2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str || !str[0])
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (free(str), NULL);
	str2 = malloc(ft_strlen(&str[i]));
	if (!str2)
		return (0);
	i++;
	while (str[i])
		str2[j++] = str[i++];
	str2[j] = '\0';
	free(str);
	return (str2);
}
