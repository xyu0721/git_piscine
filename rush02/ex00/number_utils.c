/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srahman <srahman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:30:36 by srahman           #+#    #+#             */
/*   Updated: 2025/02/22 23:55:53 by srahman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static t_dict_entry	*find_number(unsigned long long num, t_dict_entry *dict)
{
	while (dict)
	{
		if (dict->number == num)
			return (dict);
		dict = dict->next;
	}
	return (NULL);
}

void	print_number_word(unsigned long long num, t_dict_entry *dict)
{
	t_dict_entry	*entry;

	entry = find_number(num, dict);
	if (entry)
	{
		ft_putstr(entry->word);
		ft_putstr(" ");
	}
}

int	process_three_digits(unsigned long long num, t_dict_entry *dict)
{
	if (num >= 100)
	{
		print_number_word(num / 100, dict);
		print_number_word(100, dict);
		num %= 100;
		if (num > 0)
			ft_putstr("and ");
	}
	if (num >= 20)
	{
		print_number_word((num / 10) * 10, dict);
		if (num % 10)
			print_number_word(num % 10, dict);
	}
	else if (num > 0)
		print_number_word(num, dict);
	return (1);
}
