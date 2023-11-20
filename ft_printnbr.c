/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 06:25:21 by lsaumon           #+#    #+#             */
/*   Updated: 2023/11/20 15:02:44 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_setbase(char type)
{
	char	*base;

	if (type == 'u' || type == 'd' || type == 'i')
		base = "0123456789";
	if (type == 'x' || type == 'p')
		base = "0123456789abcdef";
	if (type == 'X')
		base = "0123456789ABCDEF";
	return (base);
}

static size_t	ft_printnbr_base(unsigned long nb, const char *base)
{
	size_t	i;
	size_t	size;

	size = 0;
	i = ft_strlen(base);
	if (nb >= i)
	{
		size += ft_printnbr_base(nb / i, base);
	}
	size += ft_printchar(base[nb % i]);
	return (size);
}

size_t	ft_printptr(unsigned long ptr, char type)
{
	const char	*base;

	base = ft_setbase(type);
	if (type == 'p')
	{
		ft_printchar('0');
		ft_printchar('x');
		if (type >= 0)
			ft_printchar('0');
		ft_printnbr_base((unsigned long)ptr, base);
	}
	return (ptr);
}

size_t	ft_printnbr(long nb, char type)
{
	const char	*base;
	size_t		size;

	size = 0;
	base = ft_setbase(type);
	if (type == 'd' || type == 'i')
	{
		if (nb < 0)
		{
			ft_printchar('-');
			nb = -nb;
			size++;
		}
		size += ft_printnbr_base(nb, base);
	}
	if (type == 'u' || type == 'x' || type == 'X')
	{
		size += ft_printnbr_base((unsigned long)nb, base);
	}
	return (size);
}
