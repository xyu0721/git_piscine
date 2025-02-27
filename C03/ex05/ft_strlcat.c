/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:23:03 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/11 14:41:14 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	len_str(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	k;
	unsigned int	max_copy;
	unsigned int	d;
	unsigned int	s;

	d = len_str(dest);
	s = len_str(src);
	if (size <= d)
	{
		return (size + s);
	}
	max_copy = size - d - 1;
	k = 0;
	while (k < max_copy)
	{
		if (src[k] == '\0')
			break ;
		dest[d + k] = src[k];
		k++;
	}
	dest[d + k] = '\0';
	return (s + d);
}

// int main()
// {
//     char str1[20] = "Hello, ";
//     char str2[] = "world!";
//     char str3[5] = "A";
//     char str4[] = "BCDEFGHI";

//     unsigned int result;

//     printf("==== Test 1: Normal case ====\n");
//     printf("Before: \"%s\"\n", str1);
//     result = ft_strlcat(str1, str2, sizeof(str1));
//     printf("After: \"%s\"\n", str1);

//     printf("==== Test 2: Small buffer ====\n");
//     printf("Before: \"%s\"\n", str3);
//     result = ft_strlcat(str3, str4, sizeof(str3));
//     printf("After: \"%s\"\n", str3);

//     return 0;
// }
