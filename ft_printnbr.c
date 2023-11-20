/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 06:25:21 by lsaumon           #+#    #+#             */
/*   Updated: 2023/11/20 11:03:41 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_setbase(char type)
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

void	ft_printnbr_base(unsigned long nb, const char *base)
{
	size_t	i;

	i = ft_strlen(base);
	if (nb >= i)
	{
		ft_printnbr_base(nb / i, base);
	}
	ft_printchar(base[nb % i]);
}

void	ft_printnumber(long nb, char type)
{
	const char	*base;

	base = ft_setbase(type);
	if (type == 'd' || type == 'i')
	{
		if (nb < 0)
		{
			ft_printchar('-');
			nb = -nb;
		}
		ft_printnbr_base(nb, base);
	}
	if (type == 'p')
	{
		ft_printchar('0');
		ft_printchar('x');
		if (type == NULL)
			ft_printchar('0');
		ft_printnbr_base((unsigned long)nb, base);
	}
	if (type == 'u' || type == 'x' || type == 'X')
	{
		ft_printnbr_base((unsigned long)nb, base);
	}
}
size_t	ft_printnbr(long nb, char type)
{
	
}