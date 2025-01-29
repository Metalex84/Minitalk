/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejango <alejango@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:13:22 by alejango          #+#    #+#             */
/*   Updated: 2023/12/01 11:55:41 by alejango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_switch(const char format, va_list ap)
{
	if (format == 'c')
		return (ft_print_char(va_arg(ap, int)));
	else if (format == 's')
		return (ft_print_str(va_arg(ap, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_print_int(va_arg(ap, int), 1));
	else if (format == 'u')
		return (ft_print_uint(va_arg(ap, unsigned int), 1));
	else if (format == 'x')
		return (ft_print_hex(va_arg(ap, unsigned int), 0, 1));
	else if (format == 'X')
		return (ft_print_hex(va_arg(ap, unsigned int), 1, 1));
	else if (format == 'p')
		return ((ft_print_str("0x") + ft_print_ptr(va_arg(ap, uintptr_t), 1)));
	else if (format == '%')
		return (ft_print_char('%'));
	else
		return (ft_print_char('%') + ft_print_char(format));
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		ret;

	ret = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			ret += ft_switch(*fmt, ap);
		}
		else
			ret += ft_print_char(*fmt);
		fmt++;
	}
	va_end(ap);
	return (ret);
}
