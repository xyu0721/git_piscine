/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:42:35 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/19 14:22:36 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_combn_recursive(int *arr, int index, int n, int start)
{
	int	i;

	i = 0;
	if (index == n)
	{
		while (i < n)
		{
			ft_putchar(arr[i] + '0');
			i++;
		}
		if (arr[0] != (10 - n))
			write(1, ", ", 2);
		return ;
	}
	i = start;
	while (i < 10)
	{
		arr[index] = i;
		ft_print_combn_recursive(arr, index + 1, n, i + 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	arr[10];

	ft_print_combn_recursive(arr, 0, n, 0);
}
int main(void)
{
	ft_print_combn(-1);
}
