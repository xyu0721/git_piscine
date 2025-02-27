/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:27:30 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/10 14:33:35 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	if (size == 0)
	{
		return (i);
	}
	while (j < size - 1 && src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (i);
}

// int main(void)
// {
// 	char src[] = "Hello, 42!";
// 	char dest1[20];
// 	char dest2[6];
// 	char dest3[1];

// 	unsigned int len1 = ft_strlcpy(dest1, src, sizeof(dest1));
// 	unsigned int len2 = ft_strlcpy(dest2, src, sizeof(dest2));
// 	unsigned int len3 = ft_strlcpy(dest3, src, sizeof(dest3));

// 	printf("Source: \"%s\"\n", src);
// 	printf("dest1 (size 20) → \"%s\" (Return: %u)\n", dest1, len1);
// 	printf("dest2 (size 6)  → \"%s\" (Return: %u)\n", dest2, len2);
// 	printf("dest3 (size 1)  → \"%s\" (Return: %u)\n", dest3, len3);

// 	return 0;
// }
