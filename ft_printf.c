/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:33:37 by lsaumon           #+#    #+#             */
/*   Updated: 2023/11/20 11:05:15 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_formats(va_list args, const char formats)
{
	int	printlen;

	printlen = 0;
	if (formats == 'c')
		return (printlen += ft_printchar(va_arg(args, int)));
	else if (formats == 's')
		return (printlen += ft_printstr(va_arg(args, int)));
	else if (formats == 'p')
		return (printlen += ft_printnbr(va_arg(args, int), formats));
	else if (formats == 'd' || formats == 'i')
		return (printlen += ft_printnbr(va_arg(args, int), formats));
	else if (formats == 'u')
		return (printlen += ft_printnbr(va_arg(args, unsigned int), formats));
	else if (formats == 'x' || formats == 'X')
		return (printlen += ft_printnbr(va_arg(args, unsigned int), formats));
	else if (formats == '%')
		return (printlen += ft_printpercent());
}

int		ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	size_t	l;
	
	va_start(args, str);
	i = 0;
	l = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			l += ft_printf_formats(args, str);
			i++;
		}
		if (str[i] != '%')
		{
			l += ft_printchar(str[i]);
			i++;
		}
	}
	va_end(args);
	return (l);
}
