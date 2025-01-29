/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejango <alejango@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:00:13 by alejango          #+#    #+#             */
/*   Updated: 2023/12/01 11:42:42 by alejango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(uintptr_t nbr, int first)
{
	static int	ret = 0;
	char		*base;

	if (first == 1)
		ret = 0;
	base = "0123456789abcdef";
	if (nbr > 15)
	{
		ft_print_ptr(nbr / 16, 0);
		ft_print_ptr(nbr % 16, 0);
	}
	else
		ret += ft_print_char(base[nbr]);
	return (ret);
}
