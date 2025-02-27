/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:28:02 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/10 14:20:24 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!is_num(str[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

// int main(void)
// {
// 	printf("%d\n", ft_str_is_numeric("ABCHS1"));
// 	printf("%d\n", ft_str_is_numeric("12387128"));
// 	printf("%d\n", ft_str_is_numeric(""));
// }
