/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 01:40:14 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/27 03:47:32 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include <unistd.h>

void	do_op(char *n1, char *op, char *n2);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);

int		add(int a, int b);
int		sub(int a, int b);
int		mul(int a, int b);
int		divide(int a, int b);
int		mod(int a, int b);
int		ft_atoi(char *str);
int		get_ope(char *op);

#endif
