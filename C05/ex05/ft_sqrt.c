/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:29:10 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/19 02:51:04 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		return (0);
	while (i * i <= nb && i <= 46340)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}

// int main(void)
// {
//     printf("ft_sqrt(16)  = %d\n", ft_sqrt(16));
//     printf("ft_sqrt(25)  = %d\n", ft_sqrt(25));
//     printf("ft_sqrt(10)  = %d\n", ft_sqrt(10));
//     printf("ft_sqrt(0)   = %d\n", ft_sqrt(0));
//     printf("ft_sqrt(1)   = %d\n", ft_sqrt(1));
//     printf("ft_sqrt(-4)  = %d\n", ft_sqrt(-4));
//     printf("ft_sqrt(2147395600) = %d\n", ft_sqrt(2147395600));

//     return 0;
// }
