/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:18:45 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/14 11:18:59 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// int main(void)
// {
// 	char src[] = "Hello, 42!";
// 	char dest[50];

// 	printf("Before copy:\n");
// 	printf("src: %s\n", src);
// 	printf("dest: %s\n", dest);

// 	ft_strcpy(dest, src);

// 	printf("\nAfter copy:\n");
// 	printf("src: %s\n", src);
// 	printf("dest: %s\n", dest);

// 	return 0;
// }

