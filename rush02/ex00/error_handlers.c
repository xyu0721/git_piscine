/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srahman <srahman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 23:48:00 by srahman           #+#    #+#             */
/*   Updated: 2025/02/22 23:52:24 by srahman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	print_error(void)
{
	ft_putstr("Error\n");
}

void	print_dict_error(void)
{
	ft_putstr("Dict Error\n");
}

int	process_and_free(char *number, t_dict_entry *dict, int is_stdin)
{
	if (!process_number(number, dict))
	{
		if (is_stdin)
			free(number);
		free_dictionary(dict);
		print_error();
		return (1);
	}
	ft_putstr("\n");
	if (is_stdin)
		free(number);
	free_dictionary(dict);
	return (0);
}
