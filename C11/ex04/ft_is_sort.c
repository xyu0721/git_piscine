/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 00:27:14 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/27 02:22:19 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	ascending;
	int	descending;

	i = 0;
	ascending = 1;
	descending = 1;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			ascending = 0;
		if (f(tab[i], tab[i + 1]) < 0)
			descending = 0;
		i++;
	}
	return (ascending || descending);
}

// int compare(int a, int b) {
//     return (a - b);
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
//     int sorted_asc[] = {1, 2, 3, 4, 5};  // 昇順 → 1
//     int sorted_desc[] = {5, 4, 3, 2, 1}; // 降順 → 1
//     int unsorted[] = {1, 3, 2, 4, 5};    // ソートされていない → 0
//     int length = 5;

//     ft_putnbr(ft_is_sort(sorted_asc, length, &compare));  // 1
//     ft_putnbr(ft_is_sort(sorted_desc, length, &compare)); // 1
//     ft_putnbr(ft_is_sort(unsorted, length, &compare));    // 0

//     return 0;
// }
