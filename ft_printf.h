/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:34:03 by lsaumon           #+#    #+#             */
/*   Updated: 2023/11/15 08:20:37 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int ft_printf(const char *str, ...);
void	ft_printdec(int nb);
void	ft_printhexcap(int nb);
void	ft_printnbr(long nb, char type);
void	ft_printnbr_base(unsigned long nb, const char *base);
size_t	ft_printpercent();
size_t	ft_printchar(char c);
size_t	ft_strlen(const char *s);
void	ft_printstr(char *s);

#endif
