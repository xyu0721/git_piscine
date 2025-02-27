/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:17:00 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/11 11:47:47 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*ptr;

	ptr = dest;
	while (*ptr != '\0')
	{
		ptr++;
	}
	while (*src != '\0' && nb > 0)
	{
		*ptr = *src;
		ptr++;
		src++;
		nb--;
	}
	*ptr = '\0';
	return (dest);
}

// int main()
// {
//     char str1[20] = "Hello, ";
//     char str2[] = "world!";

//     printf("Before strncat: %s\n", str1);
//     ft_strncat(str1, str2, 3);
//     printf("After strncat: %s\n", str1); // "Hello, wor"

//     return 0;
// }
