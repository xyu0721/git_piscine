/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:35:39 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/16 14:39:36 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

// int main(void)
// {
//     int t[] = {5, 0, -3, 10};
//     for (int i = 0; i < 4; i++)
//     {
//printf("%d! = %d\n", t[i], ft_recursive_factorial(t[i]));
//     }
//     return (0);
// }
