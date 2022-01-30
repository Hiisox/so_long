/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmhaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:31:12 by mmhaya            #+#    #+#             */
/*   Updated: 2022/01/25 17:29:48 by mmhaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*new_win;
	t_image	img;

	mlx = mlx_init();
	new_win = mlx_new_window(mlx, 400, 200, "ZEEEEEEBIIII");
	img.img = mlx_new_image(mlx, 400, 200);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_string_put(mlx, new_win, 100, 100, 0xFFFFFFFF, "Zeeeeebiiii");
	//my_mlx_pixel_put(&img, 400, 415, 0xFFFFFFFF);
	//mlx_put_image_to_window(mlx, new_win, img.img, 0, 0);
	mlx_loop(mlx);
}
