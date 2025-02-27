/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:41:05 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/26 20:41:06 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

void	solve_bsq(t_map *map)
{
	int	**dp;
	int	max_info[3];

	if (map->rows == 1 && map->cols == 1 && map->map[0][0] == map->empty)
	{
		map->map[0][0] = map->full;
		return ;
	}
	dp = (int **)malloc(map->rows * sizeof(int *));
	init_dp(dp, map, max_info);
	calculate_dp(dp, map, max_info);
	fill_map(map, max_info[1], max_info[2], max_info[0]);
	free_dp(dp, map->rows);
}
