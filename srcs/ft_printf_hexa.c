/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmhaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:20:37 by mmhaya            #+#    #+#             */
/*   Updated: 2022/02/28 17:16:54 by mmhaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putnbr_hexa(unsigned int n, const char chara)
{
	if (n >= 16)
	{
		ft_putnbr_hexa(n / 16, chara);
		ft_putnbr_hexa(n % 16, chara);
	}
	else if (n < 10)
		ft_putchar_retlen(n + 48);
	else if ((n >= 10 && n < 16) && (chara == 'x'))
		ft_putchar_retlen(n - 10 + 'a');
	else
		ft_putchar_retlen(n - 10 + 'A');
	return (ft_nbrlen_hexa(n));
}

int	ft_nbrlen_hexa(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}
