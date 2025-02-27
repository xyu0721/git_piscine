/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:56:18 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/10 14:11:21 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char src[] = "Hello, 42!";
// 	char dest1[20];
// 	char dest2[20];

// 	ft_strncpy(dest1, src, 5);
// 	ft_strncpy(dest2, src, 20);

// 	printf("n = 5  -> dest1: %s\n", dest1);
// 	printf("n = 20 -> dest2: %s\n", dest2);

// 	return 0;
// }
