/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:40:43 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/26 20:40:44 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

t_map	*parse_stdin(void)
{
	char	buffer[4096];
	int		bytes;
	int		fd;
	t_map	*map;

	bytes = read(0, buffer, 4096);
	if (bytes <= 0)
	{
		map_error();
		return (NULL);
	}
	fd = open(".tmp_map", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd < 0)
	{
		map_error();
		return (NULL);
	}
	write(fd, buffer, bytes);
	close(fd);
	map = parse_map(".tmp_map");
	return (map);
}

void	process_map(char *filename)
{
	t_map	*map;

	if (filename == NULL)
		map = parse_stdin();
	else
		map = parse_map(filename);
	if (!map)
		return ;
	solve_bsq(map);
	print_map(map);
	free_map(map);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
	{
		process_map(NULL);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		process_map(argv[i]);
		if (i < argc - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
