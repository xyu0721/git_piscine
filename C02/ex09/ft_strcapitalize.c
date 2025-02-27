/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 09:57:31 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/10 14:31:20 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_alnum(char c)
{
	int	upper;
	int	lower;
	int	digit;

	upper = (c >= 'A' && c <= 'Z');
	lower = (c >= 'a' && c <= 'z');
	digit = (c >= '0' && c <= '9');
	return (upper || lower || digit);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (new_word)
				str[i] -= 32;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (!new_word)
				str[i] += 32;
		}
		new_word = !is_alnum(str[i]);
		i++;
	}
	return (str);
}

// int main(void)
// {
// 	char str1[] = "salut, comment tu vas ? 42mots;
// 	quarante-deux cinquante+et+un";
// 	printf("Before: %s\n", str1);
// 	printf("After:  %s\n", ft_strcapitalize(str1));
// }
