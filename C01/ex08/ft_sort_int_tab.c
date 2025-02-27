/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:10:55 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/22 15:09:15 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;
	int	needswap;

	i = 0;
	needswap = 1;
	while (needswap == 1)
	{
		needswap = 0;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				needswap = 1;
			}
			i++;
		}
	}
}

// int main(void)
// {
// 	int tab[] = {3, 5, 1, 4, 2};
// 	int size = 5;

// 	int i = 0;
// 	printf("Before: ");
// 	while (i < size)
// 	{
// 		printf("%d ", tab[i]);
// 		i++;
// 	}
// 	printf("\n");

// 	ft_sort_int_tab(tab, size);

// 	i = 0;
// 	printf("After:  ");
// 	while (i < size)
// 	{
// 		printf("%d ", tab[i]);
// 		i++;
// 	}
// 	printf("\n");

// 	return 0;
// }
