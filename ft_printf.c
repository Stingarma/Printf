/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:33:37 by lsaumon           #+#    #+#             */
/*   Updated: 2023/11/10 11:56:02 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write (1, s[i], 1);
		i++;
	}
}

char	*ft_setbase(char type)
{
	if (type == 'u' || type == 'd' || type == 'i')
		return ("0123456789");
	if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	if (type == 'X')
		return ("0123456789ABCDEF");
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
	void	*p;
	int		i;
	int		d;
	unsigned int	u;
	int		index;

	i = 0;
	while (str[index])
	{
		if (str[index] == "%")
		{
			if (str[index + 1] == 'c')
			{
				c = va_arg(args, char);
				ft_printchar(c);
			}
			if (str[index + 1] == 's')
			{
				s = va_arg(args, char *);
				ft_printstr(s);
			}
			if (str[index + 1] == 'p')
			{
				p = va_arg(args, void *);
				ft_printnbr(p);
			}
			if (str[index + 1] == 'd' || str[index + 1] == 'i')
			{
				i = va_arg(args, int);
				d = va_arg(args, int);
				ft_printnbr(i);
				ft_printnbr(d);
			}
			if (str[i + 1] == 'u')
			{
				u = va_arg(args, unsigned int);
				
			}
			if (str[index + 1] == 'x' || str[index + 1] == 'X')
			{
				
			}
			if (str[index + 1] == "%")
			{
				write(1, "%", 1);
			}
		}
	}
}