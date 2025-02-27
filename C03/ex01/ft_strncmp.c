/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:39:32 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/11 12:17:26 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// int main() {
//     char str1[] = "hello";
//     char str2[] = "hello";
//     char str3[] = "hella";
//     char str4[] = "hellz";

//     printf("(\"hello\", \"hello\", 5) = %d\n", ft_strncmp(str1, str2, 5));
//     printf("(\"hello\", \"hella\", 5) = %d\n", ft_strncmp(str1, str3, 5));
//     printf("(\"hello\", \"hellz\", 4) = %d\n", ft_strncmp(str1, str4, 4));
//     printf("(\"hello\", \"hellz\", 5) = %d\n", ft_strncmp(str1, str4, 5));

//     return 0;
// }
