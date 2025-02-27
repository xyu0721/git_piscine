/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:04:17 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/24 23:59:05 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char *))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]))
			return (1);
		i++;
	}
	return (0);
}

// int contains_hello(char *str) {
//     int i = 0;
//     while (str[i]) {
//         if (str[i] == 'h' && str[i + 1] == 'e'
//         && str[i + 2] == 'l' && str[i + 3] == 'l' && str[i + 4] == 'o')
//             return 1;
//         i++;
//     }
//     return 0;
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
//     char *tab1[] = {"hi", "world", "hello", "test", NULL};
//     char *tab2[] = {"abc", "xyz", "123", NULL};

//     ft_putnbr(ft_any(tab1, &contains_hello)); // 1
//     ft_putnbr(ft_any(tab2, &contains_hello)); // 0

//     return 0;
// }
