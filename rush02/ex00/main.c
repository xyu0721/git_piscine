/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srahman <srahman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:13:02 by srahman           #+#    #+#             */
/*   Updated: 2025/02/22 23:55:10 by srahman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static char	*read_from_stdin(void)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	char	*number;

	bytes_read = read(0, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (NULL);
	buffer[bytes_read] = '\0';
	while (bytes_read > 0 && (buffer[bytes_read - 1] == '\n'
			|| buffer[bytes_read - 1] == '\r'))
		buffer[--bytes_read] = '\0';
	if (!is_valid_number(buffer))
		return (NULL);
	number = ft_strdup(buffer);
	return (number);
}

static void	set_args(int argc, char **argv, char **dict_path, char **number)
{
	if (argc == 1)
	{
		*dict_path = DEFAULT_DICT;
		*number = read_from_stdin();
	}
	else if (argc == 2)
	{
		*dict_path = DEFAULT_DICT;
		if (!is_valid_number(argv[1]))
			*number = NULL;
		else
			*number = argv[1];
	}
	else
	{
		*dict_path = argv[1];
		if (!is_valid_number(argv[2]))
			*number = NULL;
		else
			*number = argv[2];
	}
}

static int	init_dict(char *dict_path, char *number,
	t_dict_entry **dict, int is_stdin)
{
	if (!number)
	{
		print_error();
		return (0);
	}
	*dict = read_dictionary(dict_path);
	if (!*dict)
	{
		if (is_stdin)
			free(number);
		print_dict_error();
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_dict_entry	*dict;
	char			*dict_path;
	char			*number;
	int				is_stdin;

	if (argc > 3)
	{
		print_error();
		return (1);
	}
	is_stdin = (argc == 1);
	set_args(argc, argv, &dict_path, &number);
	if (!init_dict(dict_path, number, &dict, is_stdin))
		return (1);
	return (process_and_free(number, dict, is_stdin));
}
