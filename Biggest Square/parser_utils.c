/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:40:47 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/26 20:40:48 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (i < map->rows)
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
		free(map);
	}
}

void	map_error(void)
{
	write(2, "map error\n", 10);
}

int	is_valid_char(char c, t_map *map)
{
	return (c == map->empty || c == map->obstacle || c == map->full);
}
