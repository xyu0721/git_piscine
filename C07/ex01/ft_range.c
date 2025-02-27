/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 08:43:25 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/25 04:43:12 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*arr;
	int	range;

	i = 0;
	range = max - min;
	if (min >= max)
		return (NULL);
	arr = (int *)malloc((range) * sizeof(int));
	if (!arr)
		return (NULL);
	while (min < max)
	{
		arr[i] = min;
		i++;
		min++;
	}
	return (arr);
}

// int main(void)
// {
//     int min = 3;
//     int max = 8;
//     int *range;
//     int i;

//     range = ft_range(min, max);
//     if (range == NULL)
//     {
//         printf("Failed to allocate range or invalid range.\n");
//         return 1;
//     }
//     for (i = 0; i < (max - min); i++)
//     {
//         printf("%d ", range[i]);
//     }
//     printf("\n");

//     free(range);
//     return 0;
// }
