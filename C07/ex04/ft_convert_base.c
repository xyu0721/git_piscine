/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 04:40:16 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/25 04:40:27 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str);
int		ft_get_num_len(int nbr, int base_len);
int		ft_atoi_base(char *str, char *base);
char	*ft_itoa_base(int nbr, char *base_to);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] == 127)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_get_num_len(int nbr, int base_len)
{
	int	len;

	len = 1;
	while (nbr / base_len)
	{
		len++;
		nbr /= base_len;
	}
	return (len);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		number;
	char	*result;

	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (NULL);
	number = ft_atoi_base(nbr, base_from);
	result = ft_itoa_base(number, base_to);
	return (result);
}

// int main(void)
// {
// 	char	*base_from = "01";
// 	char	*base_to = "0123456789";
// 	char	*nbr = "10111010100";
// 	char	*result = ft_convert_base(nbr, base_from, base_to);

// 	if (result)
// 	{
// 		printf("元の数字: %s\n", nbr);
// 		printf("変換後の数字: %s\n", result);
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("error!!\n");
// 	}
// 	return (0);
// }
