/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 04:39:31 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/25 04:39:45 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	ft_get_num_len(int nbr, int base_len);
int	ft_check_base(char *base);

int	ft_get_index(char c, char *base)
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

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;
	int	base_len;
	int	digit;

	result = 0;
	sign = 1;
	base_len = ft_strlen(base);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str)
	{
		digit = ft_get_index(*str, base);
		if (digit == -1)
			break ;
		result = result * base_len + digit;
		str++;
	}
	return (result * sign);
}

char	*ft_itoa_base(int nbr, char *base)
{
	char	*result;
	int		base_len;
	int		num_len;
	int		is_negative;

	base_len = ft_strlen(base);
	is_negative = 0;
	if (nbr < 0)
		is_negative = 1;
	num_len = ft_get_num_len(nbr, base_len);
	result = malloc(sizeof(char) * (num_len + is_negative + 1));
	if (!result)
		return (NULL);
	if (is_negative)
		result[0] = '-';
	result[num_len + is_negative] = '\0';
	while (num_len > 0)
	{
		if (nbr < 0)
			result[--num_len + is_negative] = base[-(nbr % base_len)];
		else
			result[--num_len + is_negative] = base[nbr % base_len];
		nbr /= base_len;
	}
	return (result);
}
