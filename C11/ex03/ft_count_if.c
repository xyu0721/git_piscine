/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 00:22:11 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/25 03:37:21 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < length && tab[i])
	{
		if (f(tab[i]))
			count++;
		i++;
	}
	return (count);
}

// // 例: 文字列が "a" を含む場合に1を返す関数
// int contains_a(char *str) {
//     int i = 0;
//     while (str[i]) {
//         if (str[i] == 'a')
//             return 1;
//         i++;
//     }
//     return 0;
// }

// // 標準出力に数値を表示する関数 (writeのみ使用)
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
//     char *tab[] = {"apple", "banana", "cherry", "grape", "kiwi", NULL};
//     int length = 5;  // 配列の長さ

//     ft_putnbr(ft_count_if(tab, length, &contains_a)); //3つが"a"を含む → 3

//     return 0;
// }
