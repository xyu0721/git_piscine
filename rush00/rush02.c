/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:44:15 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/09 15:53:42 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	top(int d)
{
	int	i;

	i = 1;
	ft_putchar('A');
	if (d == 2)
	{
		ft_putchar('A');
	}
	else
	{
		while (i < d - 1)
		{
			ft_putchar('B');
			i++;
			if (i == d -1)
			{
				ft_putchar('A');
			}
		}
	}
	ft_putchar('\n');
}

void	mid(int e)
{
	int	j;

	j = 1;
	ft_putchar('B');
	if (e == 2)
	{
		ft_putchar('B');
	}
	else
	{
		while (j < e - 1)
		{
			ft_putchar(' ');
			j++;
			if (j == e - 1)
			{
				ft_putchar('B');
			}
		}
	}
	ft_putchar('\n');
}

void	bot(int f)
{
	int	k;

	k = 1;
	ft_putchar('C');
	if (f == 2)
	{
		ft_putchar('C');
	}
	else
	{
		while (k < f - 1)
		{
			ft_putchar('B');
			k++;
			if (k == f -1)
			{
				ft_putchar('C');
			}
		}
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	g;

	g = 1;
	if (x > 0 && y > 0)
	{
		top(x);
		while (g <= y - 2)
		{
			mid(x);
			g++;
		}
		if (y != 1)
		{
			bot(x);
		}
	}
	else
	{
		write(1, "Argument must be positive integer.", 35);
		ft_putchar('\n');
	}
}

int	myatoi(char *str)
{
	int	num;

	num = 0;
	while (*str != '\0')
	{
		num += *str - 48;
		num *= 10;
		str++;
	}
	num /= 10;
	return (num);
}
