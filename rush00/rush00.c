/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:30:38 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/09 17:55:07 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	top(int d)
{
	int	i;

	i = 1;
	ft_putchar('o');
	if (d == 2)
	{
		ft_putchar('o');
	}
	else
	{
		while (i < d - 1)
		{
			ft_putchar('-');
			i++;
			if (i == d -1)
			{
				ft_putchar('o');
			}
		}
	}
	ft_putchar('\n');
}

void	mid(int e)
{
	int	j;

	j = 1;
	ft_putchar('|');
	if (e == 2)
	{
		ft_putchar('|');
	}
	else
	{
		while (j < e - 1)
		{
			ft_putchar(' ');
			j++;
			if (j == e - 1)
			{
				ft_putchar('|');
			}
		}
	}
	ft_putchar('\n');
}

void	bot(int f)
{
	int	k;

	k = 1;
	ft_putchar('o');
	if (f == 2)
	{
		ft_putchar('o');
	}
	else
	{
		while (k < f - 1)
		{
			ft_putchar('-');
			k++;
			if (k == f -1)
			{
				ft_putchar('o');
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
