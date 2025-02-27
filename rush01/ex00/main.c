/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:52:23 by tnaito            #+#    #+#             */
/*   Updated: 2025/02/16 17:49:28 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	solution(int tab[4][4], int hint[16], int pos)
{
	int	size;

	if (pos == 16)
		return (1);
	size = 0;
	while (++size <= 4)
	{
		if (dual_check(tab, pos, size) == 0)
		{
			tab[pos / 4][pos % 4] = size;
			if (hint_check(tab, pos, hint) == 0)
			{
				if (solution(tab, hint, pos + 1) == 1)
					return (1);
			}
			else
				tab[pos / 4][pos % 4] = 0;
		}
	}
	return (0);
}

void	display_solution(int tab[4][4])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			ft_putnbr(tab[i][j]);
			if (j != 3)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

int	main(int ac, char **av)
{
	int	tab[4][4];
	int	*hint;

	ft_memset(tab, 0, sizeof(tab) / sizeof(int));
	if (check(ac, av) == 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	hint = get_numbers(av[1]);
	if (solution(tab, hint, 0) == 1)
		display_solution(tab);
	else
		ft_putstr("Error\n");
	return (0);
}
