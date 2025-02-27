/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 09:06:07 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/10 14:21:33 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_lowcase(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!is_lowcase(str[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

// int main(void)
// {
// 	printf("%d\n", ft_str_is_lowercase("ABcHs1"));
// 	printf("%d\n", ft_str_is_lowercase("lsciwa"));
// 	printf("%d\n", ft_str_is_lowercase(""));
// }
