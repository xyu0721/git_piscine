/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 00:35:18 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/25 05:39:54 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		swapped;
	char	*temp;

	if (!tab)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (tab[i + 1])
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
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

// void ft_putstr(char *str) {
//	 int i = 0;
//     while (str[i]) {
//         write(1, &str[i], 1);
//         i++;
//     }
//     write(1, "\n", 1);
// }

// int main() {
//     char *tab[] = {"banana", "apple", "cherry", "grape", "kiwi", NULL};

//     ft_sort_string_tab(tab);

//     int i = 0;
//     while (tab[i]) {
//         ft_putstr(tab[i]);
//         i++;
//     }

//     return 0;
// }
