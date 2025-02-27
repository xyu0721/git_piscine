/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srahman <srahman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:34:36 by srahman           #+#    #+#             */
/*   Updated: 2025/02/21 22:51:56 by srahman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	process_large_number(unsigned long long num,
		unsigned long long div, t_dict_entry *dict)
{
	if (num >= div)
	{
		process_three_digits(num / div, dict);
		print_number_word(div, dict);
		num %= div;
		if (num > 0)
			ft_putstr("and ");
	}
	return (num);
}

int	process_number(char *number, t_dict_entry *dict)
{
	unsigned long long	num;

	if (!is_valid_number(number))
		return (0);
	num = ft_atoi(number);
	if (num == 0)
	{
		print_number_word(0, dict);
		return (1);
	}
	if (ft_strlen(number) > 12)
		return (0);
	num = process_large_number(num, 1000000000, dict);
	num = process_large_number(num, 1000000, dict);
	num = process_large_number(num, 1000, dict);
	return (process_three_digits(num, dict));
}
