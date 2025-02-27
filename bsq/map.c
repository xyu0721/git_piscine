/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:12:51 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/26 22:12:52 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (!fd_error(fd))
		return (-1);
	return (fd);
}

char	*initialize_buffer(void)
{
	char	*buffer;

	buffer = (char *)malloc(BUFFER_SIZE);
	if (!buffer)
		map_error();
	return (buffer);
}

char	*expand_buffer(char *buffer, char *tmp, int *total_bytes, int bytes)
{
	char	*new_buffer;
	int		j;

	new_buffer = (char *)malloc(*total_bytes + bytes + 1);
	if (!new_buffer)
	{
		map_error();
		free(buffer);
		return (NULL);
	}
	j = -1;
	while (++j < *total_bytes)
	{
		new_buffer[j] = buffer[j];
	}
	j = 0;
	while (j < bytes)
	{
		new_buffer[*total_bytes + j] = tmp[j];
		j++;
	}
	new_buffer[*total_bytes + bytes] = '\0';
	free(buffer);
	*total_bytes += bytes;
	return (new_buffer);
}

char	*read_map_file(int fd, int *total_bytes)
{
	char	*buffer;
	char	tmp[BUFFER_SIZE];
	int		bytes;

	buffer = initialize_buffer();
	if (!buffer)
		return (NULL);
	*total_bytes = 0;
	bytes = read(fd, tmp, BUFFER_SIZE);
	while (bytes > 0)
	{
		buffer = expand_buffer(buffer, tmp, total_bytes, bytes);
		if (!buffer)
			return (NULL);
		bytes = read(fd, tmp, BUFFER_SIZE);
	}
	close(fd);
	return (buffer);
}

t_map	*initialize_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		map_error();
	return (map);
}
