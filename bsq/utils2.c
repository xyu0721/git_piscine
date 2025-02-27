/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:40:54 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/26 22:03:58 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			write(1, &map->map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	cleanup_map_on_error(char *buffer, t_map *map)
{
	free(buffer);
	free_map(map);
}
