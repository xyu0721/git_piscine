/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:06:00 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/10 14:35:20 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_puthex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, &hex[c / 16], 1);
	write(1, &hex[c % 16], 1);
}

void	ft_putaddr(unsigned long long addr)
{
	int		i;
	char	addr_str[16];

	i = 15;
	while (i >= 0)
	{
		addr_str[i] = "0123456789abcdef"[addr % 16];
		addr /= 16;
		i--;
	}
	write(1, addr_str, 16);
	write(1, ":", 1);
	write(1, " ", 1);
}

void	ft_print_hex_dump(unsigned char *ptr, unsigned int size, unsigned int i)
{
	unsigned int	j;

	j = 0;
	while (j < 16)
	{
		if (i + j < size)
			ft_puthex(ptr[i + j]);
		else
			write(1, "  ", 2);
		if (j % 2 == 1)
			write(1, " ", 1);
		j++;
	}
}

void	ft_print_ascii(unsigned char *ptr, unsigned int size, unsigned int i)
{
	unsigned int	j;

	j = 0;
	while (j < 16 && i + j < size)
	{
		if (ptr[i + j] >= 32 && ptr[i + j] <= 126)
			write(1, &ptr[i + j], 1);
		else
			write(1, ".", 1);
		j++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*ptr;

	ptr = (unsigned char *)addr;
	if (size == 0)
		return (addr);
	i = 0;
	while (i < size)
	{
		ft_putaddr((unsigned long long)(ptr + i));
		ft_print_hex_dump(ptr, size, i);
		ft_print_ascii(ptr, size, i);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}

// int main(void)
// {
// 	char data[] = "Bonjour les aminches..\nc. est fo";
// 	ft_print_memory(data, sizeof(data));
// 	return (0);
// }
