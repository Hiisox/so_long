/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmhaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:31:12 by mmhaya            #+#    #+#             */
/*   Updated: 2022/01/25 17:29:48 by mmhaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"

typedef struct s_map
{
	int	c;
	int	e;
	int	p;
}			t_map;

int		ft_strchr(const char *str);
int		ft_strlen(char *str);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*only_str(char *str);
char	*only_areturn(char *str);
char	*get_next_line(int fd);
int		parsing_map2(int fd, int len, char *str, t_map map);
int		parsing_map(char **av);
int		check_p(char *str);
int		check_e(char *str);
int		check_c(char *str);
int		check_wall(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strlen_map(char *str);
int		check_line(char *str, int len);

#endif
