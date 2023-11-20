/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 06:08:57 by lsaumon           #+#    #+#             */
/*   Updated: 2023/11/20 11:43:16 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printchar(char c)
{
	return (write(1, &c, 1));
}

static size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (1, "(null)", 6);
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	if (i == ft_strlen(s))
		return (i);
	else
		return (-1);
}

size_t	ft_printpercent(void)
{
	return (write(1, "%", 1));
}
