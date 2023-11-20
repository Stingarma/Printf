/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:33:37 by lsaumon           #+#    #+#             */
/*   Updated: 2023/11/20 15:09:48 by lsaumon          ###   ########.fr       */
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
		printlen += ft_printptr(va_arg(args, int), formats);
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
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				return (-1);
			l += ft_printf_formats(args, str[i + 1]);
			i += 2;
		}
		else
		{
			l += ft_printchar(str[i]);
			i++;
		}
	}
	va_end(args);
	return (l);
}
// int main (void)
// {
// // 	// char	str;
// // 	// char	*str1;
// // 	int		nbr;
// // 	// unsigned int	nbr2;
// // 	// int		hexnbr;

// // 	// str = 'f';
// // 	// str1 = "Bonjour a tous";
// // 	nbr = 555;
// // 	// nbr2 = 56897;
// // 	// hexnbr = 485;
// // 	// printf("Printf : %c\n", str);
// // 	// ft_printf("Mon Printf : %c\n", str);
// // 	// printf("Printf : %s\n", str1);
// // 	// ft_printf("Mon Printf : %s\n", str1);
// // 	// printf("Printf : %p\n", str1);
// // 	// ft_printf("Mon Printf : %p\n", str1);
// // 	// printf("Printf : %i\n", nbr);
// // 	// ft_printf("Mon Printf : %i\n", nbr);
// // 	printf("%d :", printf("Printf : %d\n", nbr));
// // 	printf("%d :", ft_printf("Printf : %d\n", nbr));
// // 	// printf("Printf : %u\n", nbr2);
// // 	// ft_printf("Mon Printf : %u\n", nbr2);
// // 	// printf("Printf : %x\n", hexnbr);
// // 	// ft_printf("Mon Printf : %x\n", hexnbr);
// // 	// printf("Printf : %X\n", hexnbr);
// // 	// ft_printf("Mon Printf : %X\n", hexnbr);
// // 	// printf("Printf : %%\n");
// // 	// ft_printf("Mon Printf : %%\n");

// 		printf("%d :", ft_printf("test avec un %% a la fin : %"));
// 		fflush(stdout);
// 		printf("%d :", printf("test avec un %% a la fin : %"));

// //     // int nums[] = {10, 255, 1024, 65535, 123456789};
// //     // int n = sizeof(nums) / sizeof(nums[0]);

// //     // for (int i = 0; i < n; ++i) {
// //     //     printf("%d :", printf("Decimal: %d, Hex (lowercase): %x, Hex (uppercase): %X\n", nums[i], nums[i], nums[i]));
// // 	// 	fflush(stdout);
// // 	// 	printf("%d :", ft_printf("Decimal: %d, Hex (lowercase): %x, Hex (uppercase): %X\n", nums[i], nums[i], nums[i]));
// //     // }

// //     // // Test avec un nombre spécifique
// //     // int specific_num = 485;
// //     // printf("%d :", printf("Specific number - Decimal: %d, Hex (lowercase): %x, Hex (uppercase): %X\n", specific_num, specific_num, specific_num));
// // 	// fflush(stdout);
// // 	// printf("%d :", ft_printf("Specific number - Decimal: %d, Hex (lowercase): %x, Hex (uppercase): %X\n", specific_num, specific_num, specific_num));

// //     return 0;
// }
