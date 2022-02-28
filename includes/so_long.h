/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhamlac <lkhamlac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:31:12 by mmhaya            #+#    #+#             */
/*   Updated: 2022/02/28 17:20:02 by mmhaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# define PLAYER "./assets/player.xpm"
# define FLOOR "./assets/floor.xpm"
# define WALL "./assets/wall.xpm"
# define EXIT "./assets/exit.xpm"
# define COLLEC "./assets/collectible.xpm"

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}			t_img;

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_map
{
	int		fd;
	char	**map;
	int		x;
	int		y;
	int		c;
	int		e;
	int		p;
	t_pos	pos_p;
	int		parsing;
}			t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	int		count;
}			t_mlx;

typedef struct s_assets
{
	t_img	player;
	t_img	wall;
	t_img	exit;
	t_img	floor;
	t_img	collec;
}			t_assets;

typedef struct s_game
{
	t_assets	assets;
	t_mlx		window;
	t_map		map;
	t_img		img;
}			t_game;

int		ft_printf(const char *str, ...);
int		what_type(va_list ap, const char thetype);
int		ft_putchar_retlen(char c);
int		ft_putstr_retlen(char *str);
int		ft_putnbr(int n);
int		ft_nbrlen(int n);
int		ft_putnbr_hexa(unsigned int n, const char chara);
int		ft_nbrlen_hexa(unsigned int n);
int		ft_nbrlen_ptr(unsigned long int n);
int		ft_putnbr_ptr(unsigned long int n);
int		ft_nbrlen_unsigned(unsigned int n);
int		ft_putnbr_unsigned(unsigned int n);
void	ft_converter_ptr(unsigned long int n);
void	init_struct(t_game *game);
int		check_dim(t_game *game);
void	print_image2(t_game *game, int i, int j);
int		exit_game(t_game *game);
void	go_right(t_game *game);
void	go_down(t_game *game);
void	go_up(t_game *game);
void	go_left(t_game *game);
void	print_image(t_game *game);
int		check_wall(t_map *map, int x, int y, char next);
int		key_hook(int keycode, t_game *game);
void	go_up(t_game *game);
int		init_images(t_game *game);
void	init_window(t_game *game);
void	free_all(t_game *game);
void	parsing(int ac, char **av, t_game *game);
void	check_letters(t_game *game);
void	check_c(t_game *game);
void	check_p(t_game *game);
void	check_e(t_game *game);
void	check_border(t_game *game);
void	check_border2(t_game *game);
void	map_lenght(t_game *game);
int		parsing_arg(t_game *game);
char	**ft_get_file(int fd, int lvl);
int		get_next_line(int fd, char **line);
char	*ft_stock_line(char *str, char **line);
char	*ft_get_static(char *str, char buf[80], int len);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		check_arg(char *str);

#endif
