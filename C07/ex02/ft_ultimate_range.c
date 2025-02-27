/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 09:36:21 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/25 04:43:01 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	i = 0;
	size = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc(size * sizeof(int));
	if (!(*range))
		return (-1);
	while (i < size)
	{
		(*range)[i] = min;
		i++;
		min++;
	}
	return (size);
}

// int main(void)
// {
//     int *arr;
//     int size;
//     int i;

//     size = ft_ultimate_range(&arr, 3, 8);
//     if (size == -1)
//     {
//         printf("Memory allocation failed.\n");
//         return 1;
//     }
//     else if (size == 0)
//     {
//         printf("No range to allocate (min >= max).\n");
//         return 0;
//     }

//     i = 0;
//     while (i < size)
//     {
//         printf("%d ", arr[i]);
//         i++;
//     }
//     printf("\n");

//     free(arr);

//     return 0;
// }
