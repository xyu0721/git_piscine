/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:23:23 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/19 14:47:03 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	ch;
	int				i;
	char			hex[2];

	i = 0;
	while (str[i] != '\0')
	{
		ch = (unsigned char)str[i];
		if (ch >= 32 && ch <= 126)
			write(1, &ch, 1);
		else
		{
			write(1, "\\", 1);
			hex[0] = "0123456789abcdef"[ch / 16];
			hex[1] = "0123456789abcdef"[ch % 16];
			write(1, hex, 2);
		}
		i++;
	}
}

int main(void)
{
	char str1[] = "Coucou\ntu vas bien ?";
	char str2[] = "Hello\0\x02\x03World!";
	char str3[] = "42Tokyo\tPiscine";
	char str4[] = "NoNonPrintable";
	char str5[] = "";

	printf("Input 1: \"%s\"\nOutput 1: ", str1);
	ft_putstr_non_printable(str1);
	printf("\n\n");

	printf("Input 2: \"%s\"\nOutput 2: ", str2);
	ft_putstr_non_printable(str2);
	printf("\n\n");

	printf("Input 3: \"%s\"\nOutput 3: ", str3);
	ft_putstr_non_printable(str3);
	printf("\n\n");

	printf("Input 4: \"%s\"\nOutput 4: ", str4);
	ft_putstr_non_printable(str4);
	printf("\n\n");

	printf("Input 5: \"%s\"\nOutput 5: ", str5);
	ft_putstr_non_printable(str5);
	printf("\n\n");

	return 0;
}
