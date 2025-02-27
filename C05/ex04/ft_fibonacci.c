/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:25:50 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/16 19:32:49 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

// int main(void)
// {
// 	printf("Fibonacci(0)  = %d\n", ft_fibonacci(0));
// 	printf("Fibonacci(1)  = %d\n", ft_fibonacci(1));
// 	printf("Fibonacci(2)  = %d\n", ft_fibonacci(2));
// 	printf("Fibonacci(3)  = %d\n", ft_fibonacci(3));
// 	printf("Fibonacci(4) = %d\n", ft_fibonacci(4));
// 	printf("Fibonacci(-3) = %d\n", ft_fibonacci(-3));

//     return 0;
// }
