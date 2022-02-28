/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmhaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:24:20 by mmhaya            #+#    #+#             */
/*   Updated: 2022/02/28 17:17:03 by mmhaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_nbrlen_ptr(unsigned long int n)
{
	int	i;

	i = 2;
	if (n == 0)
		i = 3;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_putnbr_ptr(unsigned long int n)
{
	write(1, "0x", 2);
	ft_converter_ptr(n);
	return (ft_nbrlen_ptr(n));
}

void	ft_converter_ptr(unsigned long int n)
{	
	if (n >= 16)
	{
		ft_converter_ptr(n / 16);
		ft_converter_ptr(n % 16);
	}
	else if (n < 10)
		ft_putchar_retlen(n + 48);
	else
		ft_putchar_retlen(n - 10 + 'a');
}
