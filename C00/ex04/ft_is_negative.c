/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:30:11 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/06 17:46:29 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_is_negative(int n)
{
	if (n < 0)
	{
		write (1, &"N", 1);
	}
	else
	{
		write (1, &"P", 1);
	}
}

// int main(void){
// 	ft_is_negative(1);
// 	ft_is_negative(-1);
// 	ft_is_negative(0);
// }
