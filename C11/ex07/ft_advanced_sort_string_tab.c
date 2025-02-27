/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 01:19:02 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/25 01:24:57 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		swapped;
	char	*temp;

	if (!tab || !cmp)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (tab[i + 1])
		{
			if (cmp(tab[i], tab[i + 1]) > 0)
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
	}
}

// int ft_strcmp(char *s1, char *s2) {
//     int i = 0;
//     while (s1[i] && s1[i] == s2[i]) {
//         i++;
//     }
//     return (s1[i] - s2[i]);
// }

// int ft_strcmp_reverse(char *s1, char *s2)
// {
// 	return (-ft_strcmp(s1, s2));
// }

// #include <unistd.h>

// void ft_putstr(char *str) {
//     int i = 0;
//     while (str[i]) {
//         write(1, &str[i], 1);
//         i++;
//     }
//     write(1, "\n", 1);
// }

// int main() {
//     char *tab1[] = {"banana", "apple", "cherry", "grape", "kiwi", NULL};
//     char *tab2[] = {"banana", "apple", "cherry", "grape", "kiwi", NULL};

//     // 昇順ソート
//     ft_advanced_sort_string_tab(tab1, &ft_strcmp);
//     int i = 0;
//     while (tab1[i]) {
//         ft_putstr(tab1[i]);
//         i++;
//     }

//     write(1, "\n", 1);

//     // 降順ソート
//     ft_advanced_sort_string_tab(tab2, &ft_strcmp_reverse);
//     i = 0;
//     while (tab2[i]) {
//         ft_putstr(tab2[i]);
//         i++;
//     }

//     return 0;
// }
