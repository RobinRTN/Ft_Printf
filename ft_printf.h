/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrettien <rrettien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:51:10 by rrettien          #+#    #+#             */
/*   Updated: 2023/11/13 17:03:59 by rrettien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// HELPERS
int		ft_compute_size(unsigned int num, int base);
int		ft_compute_size_long(unsigned long long num, int base);
int		is_command(char c);
char	*ft_unsigned_itoa(unsigned int num);

// PRINTERS FIRST
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_printptr(unsigned long long num);
int		ft_printnbr(int i);

// PRINTERS SECOND
int		ft_print_unsigned(unsigned int num);
int		ft_printhexa(unsigned int num, char x);
int		ft_printpercent(void);

// PRINTF
int		ft_print_tree(char c, va_list args);
int		ft_parser(char *str, va_list args);
int		ft_printf(const char *format, ...);

#endif
