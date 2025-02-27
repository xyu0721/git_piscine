/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:32:44 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/06 17:59:58 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

// int main(void)
// {
// 	int c;
// 	int d;
// 	int e;
// 	int f;

// 	c = 10;
// 	d = 3;

// 	ft_div_mod(c, d, &e, &f);
// 	printf("%d, %d", e, f);
// }
