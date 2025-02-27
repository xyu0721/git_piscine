/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:58:24 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/11 14:44:33 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*s;
	char	*t;

	if (*to_find == '\0')
	{
		return (str);
	}
	while (*str != '\0')
	{
		s = str;
		t = to_find;
		while (*s != '\0' && *t != '\0' && (*s == *t))
		{
			s++;
			t++;
		}
		if (*t == '\0')
			return (str);
		str++;
	}
	return (NULL);
}

// int main()
// {
// char str[] = "Hello, world!";
// char find1[] = "world";
// char find2[] = "el";
// char find3[] = "abc";

// printf("(\"%s\", \"%s\") = %s\n", str, find1, ft_strstr(str, find1));
// printf("(\"%s\", \"%s\") = %s\n", str, find2, ft_strstr(str, find2));
// printf("(\"%s\", \"%s\") = %s\n", str, find3, ft_strstr(str, find3));

// return 0;
// }
