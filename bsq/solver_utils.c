/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:41:01 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/26 20:41:02 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

void	fill_map(t_map *map, int max_row, int max_col, int max_size)
{
	int	i;
	int	j;

	i = max_row;
	while (i > max_row - max_size)
	{
		j = max_col;
		while (j > max_col - max_size)
		{
			map->map[i][j] = map->full;
			j--;
		}
		i--;
	}
}

void	init_dp(int **dp, t_map *map, int *max_info)
{
	int	i;
	int	j;

	max_info[0] = 0;
	max_info[1] = 0;
	max_info[2] = 0;
	i = 0;
	while (i < map->rows)
	{
		dp[i] = (int *)malloc(map->cols * sizeof(int));
		j = 0;
		while (j < map->cols)
		{
			if (map->map[i][j] == map->obstacle)
				dp[i][j] = 0;
			else if (i == 0 || j == 0)
				dp[i][j] = 1;
			else
				dp[i][j] = 0;
			j++;
		}
		i++;
	}
}

static void	process_cell(t_dp_data *data, int i, int j)
{
	if (data->map->map[i][j] != data->map->obstacle)
	{
		if (i == 0 || j == 0)
		{
			data->dp[i][j] = 1;
		}
		else
		{
			data->dp[i][j] = ft_min(data->dp[i - 1][j],
					data->dp[i][j - 1], data->dp[i - 1][j - 1]) + 1;
		}
		if (data->dp[i][j] > data->max_info[0] ||
			(data->dp[i][j] == data->max_info[0] && i < data->max_info[1]) ||
			(data->dp[i][j] == data->max_info[0] && i == data->max_info[1] &&
			j < data->max_info[2]))
		{
			data->max_info[0] = data->dp[i][j];
			data->max_info[1] = i;
			data->max_info[2] = j;
		}
	}
	else
	{
		data->dp[i][j] = 0;
	}
}

void	calculate_dp(int **dp, t_map *map, int *max_info)
{
	int			i;
	int			j;
	t_dp_data	data;

	data.dp = dp;
	data.map = map;
	data.max_info = max_info;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			process_cell(&data, i, j);
			j++;
		}
		i++;
	}
}

void	free_dp(int **dp, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(dp[i]);
		i++;
	}
	free(dp);
}
