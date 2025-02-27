/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 09:19:50 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/10 14:22:57 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_prntab(char c)
{
	return (c >= 32 && c <= 126);
}

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!is_prntab(str[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

// int main(void)
// {
// 	printf("%d\n", ft_str_is_printable("ABcHs1}/c&^#"));
// 	printf("%d\n", ft_str_is_printable("\n\t"));
// 	printf("%d\n", ft_str_is_printable(""));
// }
