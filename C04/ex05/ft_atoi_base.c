/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:19:42 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/20 20:23:16 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	base_length(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i + 1;
		while (base[j])
			if (base[i] == base[j++])
				return (0);
		i++;
	}
	if (i > 1)
	{
		return (i);
	}
	else
	{
		return (0);
	}
}

int	get_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	skip_whitespace(char *str, int *i)
{
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	return (*i);
}

int	process_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	result;
	int	base_len;
	int	sign;
	int	index;

	i = 0;
	result = 0;
	base_len = base_length(base);
	if (base_len == 0)
		return (0);
	skip_whitespace(str, &i);
	sign = process_sign(str, &i);
	index = get_index(str[i], base);
	while (index != -1)
	{
		result = result * base_len + index;
		i++;
		index = get_index(str[i], base);
	}
	return (result * sign);
}

#include <stdio.h>

int main()
{
	printf("%d\n", ft_atoi_base("   ---+--+101010", "01")); // -42
	printf("%d\n", ft_atoi_base("   2A", "0123456789ABCDEF")); // 42
    printf("%d\n", ft_atoi_base("   -vn", "poneyvif")); // -42
    printf("%d\n", ft_atoi_base("   377", "01234567")); // 255
    printf("%d\n", ft_atoi_base("-2147483648", "0123456789")); //-2147483648
    printf("%d\n", ft_atoi_base("   64", "0123456789ABCDEF")); // 100
    printf("%d\n", ft_atoi_base("   42", "0123456789")); // 42
    printf("%d\n", ft_atoi_base("   +++-+10", "01")); // -2
    printf("%d\n", ft_atoi_base("   10a", "0123456789")); // 10
    printf("%d\n", ft_atoi_base("   42", "0")); // 0
    printf("%d\n", ft_atoi_base("   42", "01234-56789")); // 0
    return 0;
}
