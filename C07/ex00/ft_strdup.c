/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 00:39:31 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/18 12:10:24 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dest;
	char	*src_copy;

	len = 0;
	src_copy = src;
	while (*src)
	{
		len++;
		src++;
	}
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = src_copy[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// int main(void)
// {
// 	char *original = "Hello, world!";
// 	char *copy;

// 	copy = ft_strdup(original);
// 	if (copy == NULL)
// 	{
// 		printf("Memory allocation failed!\n");
// 		return 1;
// 	}

// 	printf("Original : %s\n", original);
// 	printf("Copy     : %s\n", copy);
// 	free(copy);

// 	return 0;
// }
