/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srahman <srahman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:13:13 by srahman           #+#    #+#             */
/*   Updated: 2025/02/21 22:51:16 by srahman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	add_entry(t_dict_entry **dict, t_dict_entry *new_entry)
{
	t_dict_entry	*current;

	if (!new_entry)
		return ;
	if (!*dict)
	{
		*dict = new_entry;
		return ;
	}
	current = *dict;
	while (current->next)
		current = current->next;
	current->next = new_entry;
}

static char	*read_line(int fd)
{
	char	buffer[2];
	char	*line;
	int		i;
	int		bytes_read;

	line = malloc(sizeof(char) * 1024);
	if (!line)
		return (NULL);
	i = 0;
	bytes_read = read(fd, buffer, 1);
	while (bytes_read > 0 && buffer[0] != '\n')
	{
		line[i++] = buffer[0];
		bytes_read = read(fd, buffer, 1);
	}
	line[i] = '\0';
	if (i == 0 && bytes_read <= 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

t_dict_entry	*read_dictionary(char *dict_path)
{
	int				fd;
	char			*line;
	t_dict_entry	*dict;
	t_dict_entry	*entry;

	fd = open(dict_path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	dict = NULL;
	line = read_line(fd);
	while (line)
	{
		entry = parse_line(line);
		if (entry)
			add_entry(&dict, entry);
		free(line);
		line = read_line(fd);
	}
	close(fd);
	return (dict);
}
