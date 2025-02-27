/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:26:20 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/20 15:25:28 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;
	int	minus_count;

	i = 0;
	sign = 1;
	result = 0;
	minus_count = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus_count++;
		i++;
	}
	if (minus_count % 2 != 0)
		sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

// int main()
// {
//     // ft_atoi の動作確認（結果を printf で表示）
//     printf("%d\n", ft_atoi("   ---+--+1234ab567")); // -1234
//     printf("%d\n", ft_atoi("  +42xyz"));            // 42
//     printf("%d\n", ft_atoi("  -+-+--+00123foo"));   // -123
//     printf("%d\n", ft_atoi("  0000567bar"));        // 567
//     printf("%d\n", ft_atoi("0"));                   // 0
//     printf("%d\n", ft_atoi("-2147483648"));         // -2147483648
//     printf("%d\n", ft_atoi("2147483647"));          // 2147483647
//     return 0;
// }
