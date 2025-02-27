/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:40:38 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/26 22:00:47 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

int	parse_number(char *buffer, int *i, int num_end)
{
	int	result;

	result = 0;
	while (*i < num_end)
	{
		if (buffer[*i] < '0' || buffer[*i] > '9')
			return (-1);
		result = result * 10 + (buffer[*i] - '0');
		(*i)++;
	}
	return (result);
}

int	get_column_count(char *buffer, int *start, t_map *map)
{
	int	col;

	col = 0;
	while (buffer[*start] != '\n' && buffer[*start] != '\0')
	{
		if (!is_valid_char(buffer[*start], map))
			return (-1);
		if (buffer[*start] == map->full)
			return (-1);
		(*start)++;
		col++;
	}
	return (col);
}

int	validate_column_count(t_map *map, int col, int row)
{
	if (row == 0)
		map->cols = col;
	else if (col != map->cols)
		return (0);
	return (1);
}

int	process_map_row(char *buffer, t_map *map, int row, int *start)
{
	t_row_info	info;
	int			col;

	col = get_column_count(buffer, start, map);
	if (col == -1)
		return (0);
	if (!validate_column_count(map, col, row))
		return (0);
	info.row = row;
	info.col = col;
	info.start = *start;
	info.buffer = buffer;
	if (!allocate_map_row(map, &info))
		return (0);
	(*start)++;
	return (1);
}

int	parse_and_validate_map(char *buffer, t_map *map, int total_bytes)
{
	int	i;

	if (!parse_map_header(buffer, map, &i)
		|| !read_map_content(buffer, map, i, total_bytes))
	{
		map_error();
		free_map(map);
		return (0);
	}
	return (1);
}
