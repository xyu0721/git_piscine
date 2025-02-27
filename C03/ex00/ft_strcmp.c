/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:13:03 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/10 21:05:16 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

// int main() {
//     char str1[] = "apple";
//     char str2[] = "apple";
//     char str3[] = "apricot";
//     char str4[] = "banana";

//     printf("strcmp(\"apple\", \"apple\") = %d\n", ft_strcmp(str1, str2));
//     printf("strcmp(\"apple\", \"apricot\") = %d\n", ft_strcmp(str1, str3));
//     printf("strcmp(\"banana\", \"apple\") = %d\n", ft_strcmp(str4, str1));

//     return 0;
// }
