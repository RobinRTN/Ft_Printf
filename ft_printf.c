/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robinrettien <robinrettien@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:51:06 by rrettien          #+#    #+#             */
/*   Updated: 2024/03/15 19:50:26 by robinrettie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_tree(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_printchar(va_arg(args, int));
	else if (c == 's')
		count += ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		count += ft_printptr(va_arg(args, unsigned long long));
	else if (c == 'i' || c == 'd')
		count += ft_printnbr(va_arg(args, int));
	else if (c == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		count += ft_printhexa(va_arg(args, unsigned int), 'x');
	else if (c == 'X')
		count += ft_printhexa(va_arg(args, unsigned int), 'X');
	else if (c == '%')
		count += ft_printpercent();
	return (count);
}

int	ft_parser(char *str, va_list args)
{
	size_t	i;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && is_command(str[i + 1]))
		{
			count += ft_print_tree(str[i + 1], args);
			i++;
		}
		else
			count += ft_printchar(str[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	count = 0;
	va_start(args, format);
	count = ft_parser((char *)format, args);
	va_end(args);
	return (count);
}
