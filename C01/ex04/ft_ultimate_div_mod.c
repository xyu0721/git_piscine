/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:23:59 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/07 19:53:22 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	i;
	int	j;

	i = *a / *b;
	j = *a % *b;
	*a = i;
	*b = j;
}

// int main(void)
// {
// 	int c;
// 	int d;
// 	c = 10;
// 	d = 3;
// 	ft_div_mod(&c, &d);
// 	printf("%d, %d", c, d);
// }
