/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejango <alejango@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:47:54 by alejango          #+#    #+#             */
/*   Updated: 2023/12/01 11:33:15 by alejango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int nbr, int first)
{
	static int	ret = 0;

	if (first == 1)
		ret = 0;
	if (nbr > 9)
	{
		ft_print_int(nbr / 10, 0);
		ft_print_int(nbr % 10, 0);
	}
	else if (nbr == INT_MIN)
	{
		ret += ft_print_str("-2147483648");
		return (ret);
	}
	else if (nbr < 0)
	{
		ret += ft_print_char('-');
		ft_print_int(-nbr, 0);
	}
	else
		ret += ft_print_char(nbr + '0');
	return (ret);
}
