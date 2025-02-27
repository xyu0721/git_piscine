/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:59:14 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/17 11:28:58 by shizhou          ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (nb % 2 == 0)
		nb++;
	while (!ft_is_prime(nb))
		nb += 2;
	return (nb);
}

// int main(void)
// {
//     int test_values[] = {0, 1, 2, 3, 4, 10,101, 200, 1000000, 2147483646};
//     int i;

//     i = 0;
//     while (i < (sizeof(test_values) / sizeof(int)))
//     {
// 	printf("(%d) = %d\n", test_values[i], ft_find_next_prime(test_values[i]));
//         i++;
//     }

//     return 0;
// }
