/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 07:10:13 by lsaumon           #+#    #+#             */
/*   Updated: 2023/11/21 07:35:55 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int main (void)
{
	char			letter = 'L';
	char			*str = "Voici un test pour Printf";
	char			*ptrnul = 0;
	int				nbr = 456;
	unsigned int	unbr = 4294967295;
	int				hex = 7897;
	char			per = 'T';

	printf("%d", printf("Ex Printf with c : %c : count of ", letter));
	fflush(stdout);
	printf("\n");
	printf("%d", ft_printf("My Printf with c : %c : count of ", letter));
	printf("\n");
	printf("\n");
	printf("%d", printf("Ex Printf with s : %s : count of ", str));
	fflush(stdout);
	printf("\n");
	printf("%d", ft_printf("My Printf with s : %s : count of ", str));
	printf("\n");
	printf("\n");
	printf("%d", printf("Ex Printf ptr adress : %p : count of ", str));
	fflush(stdout);
	printf("\n");
	printf("%d", ft_printf("My Printf ptr adress : %p : count of ", str));
	printf("\n");
	printf("\n");
	printf("%d", printf("Ex Printf with pointer null : %p : count of ", ptrnul));
	fflush(stdout);
	printf("\n");
	printf("%d", ft_printf("My Printf with pointer null : %p : count of ", ptrnul));
	printf("\n");
	printf("\n");
	printf("%d", printf("Ex Printf with d : %d : count of ", nbr));
	fflush(stdout);
	printf("\n");
	printf("%d", ft_printf("My Printf with d : %d : count of ", nbr));
	printf("\n");
	printf("\n");
	printf("%d", printf("Ex Printf with i : %i : count of ", nbr));
	fflush(stdout);
	printf("\n");
	printf("%d", ft_printf("My Printf with i : %i : count of ", nbr));
	printf("\n");
	printf("\n");
	printf("%d", printf("Ex Printf with u : %u : count of ", unbr));
	fflush(stdout);
	printf("\n");
	printf("%d", ft_printf("My Printf with u : %u : count of ", unbr));
	printf("\n");
	printf("\n");
	printf("%d", printf("Ex Printf with x : %x : count of ", hex));
	fflush(stdout);
	printf("\n");
	printf("%d", ft_printf("My Printf with x : %x : count of ", hex));
	printf("\n");
	printf("\n");
	printf("%d", printf("Ex Printf with X : %X : count of ", hex));
	fflush(stdout);
	printf("\n");
	printf("%d", ft_printf("My Printf with X : %X : count of ", hex));
	printf("\n");
	printf("\n");
	printf("%d", printf("Ex Printf percent : %% : count of ", per));
	fflush(stdout);
	printf("\n");
	printf("%d", ft_printf("My Printf percent : %% : count of ", per));
}