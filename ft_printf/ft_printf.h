/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejango <alejango@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:35:06 by alejango          #+#    #+#             */
/*   Updated: 2023/12/01 11:46:16 by alejango         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>

int	ft_printf(const char *fmt, ...);
int	ft_print_char(char c);
int	ft_print_str(char *s);
int	ft_print_int(int nbr, int first);
int	ft_print_uint(unsigned int nbr, int first);
int	ft_print_hex(unsigned int nbr, int up, int first);
int	ft_print_ptr(uintptr_t nbr, int first);

#endif
