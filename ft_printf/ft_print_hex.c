/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejango <alejango@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:50:41 by alejango          #+#    #+#             */
/*   Updated: 2023/12/01 11:40:09 by alejango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int nbr, int up, int first)
{
	static int	ret = 0;
	char		*base;

	if (first == 1)
		ret = 0;
	if (up == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr > 15)
	{
		ft_print_hex(nbr / 16, up, 0);
		ft_print_hex(nbr % 16, up, 0);
	}
	else
		ret += ft_print_char(base[nbr]);
	return (ret);
}
