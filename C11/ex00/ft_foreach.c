/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 22:11:27 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/27 03:51:45 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// void	ft_putnbr(int n)
// {
// 	char	c;

// 	if (n < 0)
// 	{
// 		write(1, "-", 1);
// 		n = -n;
// 	}
// 	if (n >= 10)
// 		ft_putnbr(n / 10);
// 	c = (n % 10) + '0';
// 	write(1, &c, 1);
// 	write(1, "\n", 1);
// }

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

// int main() {
//     int tab[] = {1, 2, 3, 4, 5};
//     int length = sizeof(tab) / sizeof(tab[0]);

//     ft_foreach(tab, length, &ft_putnbr);

//     return 0;
// }
