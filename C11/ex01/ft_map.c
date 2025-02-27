/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 22:19:34 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/25 00:24:42 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*result;
	int	i;

	if (!tab || length <= 0 || !f)
		return (NULL);
	result = (int *)malloc(sizeof(int) * length);
	if (!result)
		return (NULL);
	i = 0;
	while (i < length)
	{
		result[i] = f(tab[i]);
		i++;
	}
	return (result);
}

// 例: 受け取った数を2倍にする関数
// int	double_value(int n)
// {
//     return n * 2;
// }

// #include <unistd.h>

// void ft_putnbr(int n) {
//     char c;
//     if (n < 0) {
//         write(1, "-", 1);
//         n = -n;
//     }
//     if (n >= 10)
//         ft_putnbr(n / 10);
//     c = (n % 10) + '0';
//     write(1, &c, 1);
//     write(1, "\n", 1);
// }

// int main() {
//     int tab[] = {1, 2, 3, 4, 5};
//     int length = sizeof(tab) / sizeof(tab[0]);

//     int *mapped = ft_map(tab, length, &double_value);

//     int i = 0;
//     while (i < length) {
//         ft_putnbr(mapped[i]);
//         i++;
//     }

//     free(mapped);
//     return 0;
// }
