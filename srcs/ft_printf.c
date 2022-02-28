/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmhaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:29:09 by mmhaya            #+#    #+#             */
/*   Updated: 2022/02/28 17:16:30 by mmhaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	what_type(va_list ap, const char thetype)
{
	int	len_print;

	len_print = 0;
	if (!thetype)
		return (0);
	if (thetype == 'c')
		len_print += ft_putchar_retlen((char)va_arg(ap, int));
	else if (thetype == 's')
		len_print += ft_putstr_retlen(va_arg(ap, char *));
	else if (thetype == 'p')
		len_print += ft_putnbr_ptr(va_arg(ap, unsigned long int));
	else if (thetype == 'd' || thetype == 'i')
		len_print += ft_putnbr(va_arg(ap, int));
	else if (thetype == 'u')
		len_print += ft_putnbr_unsigned(va_arg(ap, unsigned int));
	else if (thetype == 'x' || thetype == 'X')
		len_print += ft_putnbr_hexa(va_arg(ap, unsigned int), thetype);
	else if (thetype == '%')
		len_print += ft_putchar_retlen('%');
	else
		len_print += ft_putchar_retlen(thetype);
	return (len_print);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		len_print;

	i = 0;
	len_print = 0;
	if (!str)
		return (0);
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == ' ')
			i++;
		else if (str[i] == '%' && str[i + 1])
			len_print += what_type(ap, str[++i]);
		else if (str[i] == '%' && !str[i + 1])
			break ;
		else
			len_print += ft_putchar_retlen(str[i]);
		i++;
	}
	va_end(ap);
	return (len_print);
}
