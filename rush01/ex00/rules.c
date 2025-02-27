/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:40:48 by tnaito            #+#    #+#             */
/*   Updated: 2025/02/16 17:49:09 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_col_up(int tab[4][4], int pos, int hint[16])
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	if (pos / 4 == 3)
	{
		while (i < 4)
		{
			if (tab[i][pos % 4] > max)
			{
				max = tab[i][pos % 4];
				count++;
			}
			i++;
		}
		if (hint[pos % 4] != count)
			return (1);
	}
	return (0);
}

int	check_row_right(int tab[4][4], int pos, int hint[16])
{
	int	i;
	int	max_size;
	int	count;

	i = 4;
	max_size = 0;
	count = 0;
	if (pos % 4 == 3)
	{
		while (--i >= 0)
		{
			if (tab[pos / 4][i] > max_size)
			{
				max_size = tab[pos / 4][i];
				count++;
			}
		}
		if (hint[12 + pos / 4] != count)
			return (1);
	}
	return (0);
}

int	check_col_down(int tab[4][4], int pos, int hint[16])
{
	int	i;
	int	max;
	int	count;

	i = 3;
	max = 0;
	count = 0;
	if (pos / 4 == 3)
	{
		while (i >= 0)
		{
			if (tab[i][pos % 4] > max)
			{
				max = tab[i][pos % 4];
				count++;
			}
			i--;
		}
		if (hint[4 + pos % 4] != count)
			return (1);
	}
	return (0);
}

int	check_row_left(int tab[4][4], int pos, int hint[16])
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	if (pos % 4 == 3)
	{
		while (i < 4)
		{
			if (tab[pos / 4][i] > max)
			{
				max = tab[pos / 4][i];
				count++;
			}
			i++;
		}
		if (hint[8 + pos / 4] != count)
			return (1);
	}
	return (0);
}

int	hint_check(int tab[4][4], int pos, int hint[16])
{
	if (check_row_left(tab, pos, hint) == 1)
		return (1);
	if (check_row_right(tab, pos, hint) == 1)
		return (1);
	if (check_col_down(tab, pos, hint) == 1)
		return (1);
	if (check_col_up(tab, pos, hint) == 1)
		return (1);
	return (0);
}
