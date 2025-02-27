/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:18:08 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/16 19:33:01 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	a;

	a = 1;
	if (nb < 0)
		return (0);
	while (nb > 0)
	{
		a *= nb;
		nb--;
	}
	return (a);
}

// int main(void)
// {
// 	int result = ft_iterative_factorial(0);
// 	char buffer[12];
// 	int len = sprintf(buffer, "%d\n", result);
// 	write(1, buffer, len);
// 	return (0);
// }
