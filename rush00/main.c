/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:46:40 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/09 17:49:48 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);
int		myatoi(char *str);

int	main(int argc, char **argv)
{
	int	arg1;
	int	arg2;

	argc = 3;
	arg1 = myatoi(argv[1]);
	arg2 = myatoi(argv[2]);
	rush(arg1, arg2);
	return (0);
}
