/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srahman <srahman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:45:10 by srahman           #+#    #+#             */
/*   Updated: 2025/02/21 22:51:31 by srahman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

static char	*trim_spaces(char *str)
{
	while (is_space(*str))
		str++;
	return (str);
}

t_dict_entry	*parse_line(char *line)
{
	char				*word;
	unsigned long long	num;
	char				*num_end;
	char				*word_end;

	line = trim_spaces(line);
	if (!*line || *line == '\n')
		return (NULL);
	num = ft_atoi(line);
	num_end = line;
	while (*num_end >= '0' && *num_end <= '9')
		num_end++;
	num_end = trim_spaces(num_end);
	if (*num_end != ':')
		return (NULL);
	word = trim_spaces(num_end + 1);
	if (!*word || *word == '\n')
		return (NULL);
	word_end = word;
	while (*word_end && !is_space(*word_end))
		word_end++;
	*word_end = '\0';
	return (create_entry(num, word));
}

void	process_buffer(char *buffer, t_dict_entry **dict)
{
	char	*line_start;
	char	*line_end;
	char	temp;

	line_start = buffer;
	while (*line_start)
	{
		line_end = line_start;
		while (*line_end && *line_end != '\n')
			line_end++;
		temp = *line_end;
		if (*line_end == '\n')
			*line_end = '\0';
		if (*line_start)
			add_entry(dict, parse_line(line_start));
		if (temp == '\n')
			line_start = line_end + 1;
		else
			line_start = line_end;
	}
}
