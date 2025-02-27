/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:04:35 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/16 22:05:55 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;

	i = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 0)
	{
		i *= nb;
		power--;
	}
	return (i);
}

// int main(void)
// {
//     printf("2^3  = %d\n", ft_iterative_power(2, 3));   // 8
//     printf("5^0  = %d\n", ft_iterative_power(5, 0));   // 1
//     printf("3^4  = %d\n", ft_iterative_power(3, 4));   // 81
//     printf("0^0  = %d\n", ft_iterative_power(0, 0));   // 1
//     printf("2^-2 = %d\n", ft_iterative_power(2, -2));  // 0
//     printf("7^2  = %d\n", ft_iterative_power(7, 2));   // 49
//     printf("1^100 = %d\n", ft_iterative_power(1, 100)); // 1

//     return 0;
// }
