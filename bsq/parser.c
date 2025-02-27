/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:40:50 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/26 21:46:32 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

int	parse_map_header(char *buffer, t_map *map, int *i)
{
	int	len;
	int	num_end;

	*i = 0;
	map->rows = 0;
	len = get_line_length(buffer);
	if (len < 4)
		return (0);
	map->empty = buffer[len - 3];
	map->obstacle = buffer[len - 2];
	map->full = buffer[len - 1];
	if (map->empty == map->obstacle || map->empty == map->full
		|| map->obstacle == map->full)
		return (0);
	num_end = len - 3;
	map->rows = parse_number(buffer, i, num_end);
	if (map->rows <= 0)
		return (0);
	if (buffer[len] != '\n')
		return (0);
	*i = len + 1;
	return (1);
}

int	allocate_map_row(t_map *map, t_row_info *info)
{
	int	j;

	map->map[info->row] = (char *)malloc((info->col + 1) * sizeof(char));
	if (!map->map[info->row])
		return (0);
	j = 0;
	while (j < info->col)
	{
		map->map[info->row][j] = info->buffer[info->start - info->col + j];
		j++;
	}
	map->map[info->row][info->col] = '\0';
	return (1);
}

int	verify_map_end(char *buffer, int start, int bytes, int valid_rows)
{
	int	newline_count;

	if (valid_rows == 0)
		return (0);
	newline_count = 0;
	while (start < bytes)
	{
		if (buffer[start] == '\n')
			newline_count++;
		else if (buffer[start] != '\0')
			return (0);
		start++;
	}
	if (newline_count > 1)
		return (0);
	return (1);
}

int	read_map_content(char *buffer, t_map *map, int i, int bytes)
{
	int	row;
	int	start;

	map->map = (char **)malloc(map->rows * sizeof(char *));
	if (!map->map)
		return (0);
	row = 0;
	start = i;
	while (row < map->rows && start < bytes)
	{
		if (!process_map_row(buffer, map, row, &start))
			return (0);
		row++;
	}
	if (row != map->rows)
		return (0);
	return (verify_map_end(buffer, start, bytes, row));
}

t_map	*parse_map(char *filename)
{
	int		fd;
	char	*buffer;
	int		total_bytes;
	t_map	*map;

	fd = open_file(filename);
	if (fd == -1)
		return (NULL);
	buffer = read_map_file(fd, &total_bytes);
	if (!buffer || total_bytes <= 0)
		return (NULL);
	map = initialize_map();
	if (!map)
	{
		free(buffer);
		return (NULL);
	}
	if (!parse_and_validate_map(buffer, map, total_bytes))
	{
		cleanup_map_on_error(buffer, map);
		return (NULL);
	}
	free(buffer);
	return (map);
}
