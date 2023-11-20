/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:33:37 by lsaumon           #+#    #+#             */
/*   Updated: 2023/11/20 12:04:19 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_formats(va_list args, const char formats)
{
	int	printlen;

	printlen = 0;
	if (formats == 'c')
		printlen += ft_printchar(va_arg(args, int));
	else if (formats == 's')
		printlen += ft_printstr(va_arg(args, char *));
	else if (formats == 'p')
		printlen += ft_printnbr(va_arg(args, int), formats);
	else if (formats == 'd' || formats == 'i')
		printlen += ft_printnbr(va_arg(args, int), formats);
	else if (formats == 'u')
		printlen += ft_printnbr(va_arg(args, unsigned int), formats);
	else if (formats == 'x' || formats == 'X')
		printlen += ft_printnbr(va_arg(args, unsigned int), formats);
	else if (formats == '%')
		printlen += ft_printpercent();
	return (printlen);
}

int	ft_printf(const char *str, ...)
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
			l += ft_printf_formats(args, l);
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
