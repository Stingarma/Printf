/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:33:37 by lsaumon           #+#    #+#             */
/*   Updated: 2023/11/10 09:44:18 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_printchar(char c)
{
	write(1, &c, 1);
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
void	ft_printptr(void *p)
{
	
}

int ft_printf(const char *str, ...)
{
	va_list	args;
	char	c;
	char	*s;
	void	*p;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == "%")
		{
			if (str[i + 1] == 'c')
			{
				c = va_arg(args, char);
				ft_printchar(c);
			}
			if (str[i + 1] == 's')
			{
				s = va_arg(args, char *);
				ft_printstr(s);
			}
			if (str[i + 1] == 'p')
			{
				p = va_arg(args, void *);
				
			}
			if (str[i + 1] == 'd' || str[i + 1] == 'i')
			{
				va_arg(args, int)
				
			}
		}
	}
}