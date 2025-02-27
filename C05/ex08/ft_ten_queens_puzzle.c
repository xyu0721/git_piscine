/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:58:20 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/16 20:31:28 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define SIZE 10

void	print_solution(int positions[])
{
	char	solution[SIZE + 1];
	int		i;

	i = 0;
	while (i < SIZE)
	{
		solution[i] = positions[i] + '0';
		i++;
	}
	solution[i] = '\n';
	write(1, solution, SIZE + 1);
}

int	is_safe(int p[], int col, int row)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (p[i] == row || p[i] - i == row - col || p[i] + i == row + col)
			return (0);
		i++;
	}
	return (1);
}

void	solve(int positions[], int col, int *count)
{
	int	row;

	if (col == SIZE)
	{
		print_solution(positions);
		(*count)++;
		return ;
	}
	row = 0;
	while (row < SIZE)
	{
		if (is_safe(positions, col, row))
		{
			positions[col] = row;
			solve(positions, col + 1, count);
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	positions[SIZE];
	int	count;

	count = 0;
	solve(positions, 0, &count);
	return (count);
}

// int	main(void)
// {
// 	int	result;

// 	result = ft_ten_queens_puzzle();
// 	return (0);
// }
