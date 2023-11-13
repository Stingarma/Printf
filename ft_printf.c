/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:33:37 by lsaumon           #+#    #+#             */
/*   Updated: 2023/11/13 09:07:29 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printchar(char c)
{
	write(1, &c, 1);
		return (1);
}
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
}

char	*ft_setbase(char type)
{
	char	*base;
	if (type == 'u' || type == 'd' || type == 'i')
		base = "0123456789";
	if (type == 'x' /*|| type == 'p'*/)
		base = "0123456789abcdef";
	if (type == 'X')
		base = "0123456789ABCDEF";
	return (base);
}

int		ft_printnbr(long nb, const char type)
{
	char	*base;
	int		base_size;
	size_t	size;
	
	base = ft_setbase(type);
	base_size = ft_strlen(base);
	size = 0;
	if (nb < 0)
	{
		ft_printchar('-');
		nb *= -1;
		size++;
	}
	if (nb >= base_size)
	{
		size += ft_printnbr(nb / base_size, type);
		size += ft_printnbr(nb % base_size, type);
	}
	else
	{
		size += ft_printchar(base[nb]);
	}
	return (size);
}

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
				ft_setbase(i);
				ft_setbase(d);
				ft_printnbr(nb, i);
				ft_printnbr(nb, d);
			}
			if (str[i + 1] == 'u')
			{
				u = va_arg(args, unsigned int);
				ft_setbase(u);
				ft_printnbr(nb, u);
			}
			if (str[index + 1] == 'x' || str[index + 1] == 'X')
			{
				x = va_arg(args, int);
				ft_setbase(x);
				ft_printnbr(nb, x);
				X = va_arg(args, int);
				ft_setbase(X);
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