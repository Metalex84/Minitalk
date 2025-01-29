/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejango <alejango@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:07:07 by alejango          #+#    #+#             */
/*   Updated: 2023/12/01 11:36:59 by alejango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uint(unsigned int nbr, int first)
{
	static int	ret = 0;

	if (first == 1)
		ret = 0;
	if (nbr > 9)
	{
		ft_print_uint(nbr / 10, 0);
		ft_print_uint(nbr % 10, 0);
	}
	else
		ret += ft_print_char(nbr + '0');
	return (ret);
}
