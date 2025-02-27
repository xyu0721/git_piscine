/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:33:50 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/17 11:31:26 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	if (nb % 2 == 0)
		return (0);
	i = 3;
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

// int main(void)
// {
// 	int test_values[] = {0, 1, 2, 3, 4, 5, 97, 100, 101, 200, 2147483647};
//     int i;
//     int result;

//     i = 0;
//     while (i < (sizeof(test_values) / sizeof(int)))
//     {
//         result = ft_is_prime(test_values[i]);
//         printf("T%d: ft_is_prime(%d) = %d\n",i + 1, test_values[i], result);
//         i++;
//     }

//     return 0;
// }
