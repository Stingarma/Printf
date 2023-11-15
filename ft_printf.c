/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:33:37 by lsaumon           #+#    #+#             */
/*   Updated: 2023/11/15 07:42:38 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list	args;
	char	c;
	char	*s;
	//void	*p;
	int		i;
	int		d;
	long	nb;
	int		x;
	int		X;
	unsigned int	u;
	int		index;

	index = 0;
	nb = 0;
	while (str[index])
	{
		if (str[index] == '%')
		{
			if (str[index + 1] == 'c')
			{
				c = va_arg(args, int);
				ft_printchar(c);
			}
			if (str[index + 1] == 's')
			{
				s = va_arg(args, char *);
				ft_printstr(s);
			}
			// if (str[index + 1] == 'p')
			// {
			// 	p = va_arg(args, void *);
			// 	ft_printnbr(nb, p);
			// }
			if (str[index + 1] == 'd' || str[index + 1] == 'i')
			{
				i = va_arg(args, int);
				d = va_arg(args, int);
				ft_printnbr(nb, i);
				ft_printnbr(nb, d);
			}
			if (str[i + 1] == 'u')
			{
				u = va_arg(args, unsigned int);
				ft_printnbr(nb, u);
			}
			if (str[index + 1] == 'x' || str[index + 1] == 'X')
			{
				x = va_arg(args, int);
				ft_printnbr(nb, x);
				X = va_arg(args, int);
				ft_printnbr(nb, X);
			}
			if (str[index + 1] == '%')
			{
				write(1, "%", 1);
			}
		}
	}
	if (!str[index])
		return (0);
	return (1);
}
