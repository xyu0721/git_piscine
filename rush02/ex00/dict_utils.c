/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srahman <srahman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:32:33 by srahman           #+#    #+#             */
/*   Updated: 2025/02/22 23:55:15 by srahman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i])
	{
		if (str[i] == '.' || str[i] == '-' || str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

t_dict_entry	*create_entry(unsigned long long number, char *word)
{
	t_dict_entry	*entry;

	entry = malloc(sizeof(t_dict_entry));
	if (!entry)
		return (NULL);
	entry->number = number;
	entry->word = ft_strdup(word);
	if (!entry->word)
	{
		free(entry);
		return (NULL);
	}
	entry->next = NULL;
	return (entry);
}

void	free_dictionary(t_dict_entry *dict)
{
	t_dict_entry	*temp;

	while (dict)
	{
		temp = dict->next;
		free(dict->word);
		free(dict);
		dict = temp;
	}
}
