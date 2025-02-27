/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:25:32 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/20 20:21:27 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
			if (base[i] == base[j++])
				return (0);
		i++;
	}
	return (i > 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	if (!is_valid_base(base))
		return ;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (nbr < 0)
	{
		ft_putchar('-');
		if (nbr == -2147483648)
		{
			ft_putnbr_base(-(nbr / base_len), base);
			ft_putchar(base[-(nbr % base_len)]);
			return ;
		}
		nbr = -nbr;
	}
	if (nbr >= base_len)
		ft_putnbr_base(nbr / base_len, base);
	ft_putchar(base[nbr % base_len]);
}

int main()
{
    ft_putnbr_base(42, "0123456789"); //42
    write(1, "\n", 1);
    ft_putnbr_base(-42, "01"); // -101010
    write(1, "\n", 1);
    ft_putnbr_base(42, "0123456789ABCDEF"); // 2A
    write(1, "\n", 1);
    ft_putnbr_base(42, "poneyvif"); // vn
    write(1, "\n", 1);
    ft_putnbr_base(-2147483648, "0123456789"); // -2147483648
    write(1, "\n", 1);
    ft_putnbr_base(255, "01234567"); // 377
    write(1, "\n", 1);
    ft_putnbr_base(100, "0123456789ABCDEF"); // 64
    write(1, "\n", 1);
    return 0;
}
