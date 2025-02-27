/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:42:10 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/25 04:42:53 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest + i);
}

char	*ft_empty_string(void)
{
	char	*ptr;

	ptr = (char *)malloc(1);
	if (!ptr)
		return (NULL);
	ptr[0] = '\0';
	return (ptr);
}

int	ft_total_length(int size, char **strs, char *sep)
{
	int	i;
	int	total_len;

	total_len = 0;
	i = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		i++;
	}
	total_len += ft_strlen(sep) * (size - 1);
	total_len += 1;
	return (total_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined;
	char	*write_pos;
	int		total_len;
	int		i;

	if (size == 0)
		return (ft_empty_string());
	total_len = ft_total_length(size, strs, sep);
	joined = (char *)malloc(sizeof(char) * total_len);
	if (!joined)
		return (NULL);
	write_pos = joined;
	i = 0;
	while (i < size)
	{
		write_pos = ft_strcpy(write_pos, strs[i]);
		if (i < size - 1)
			write_pos = ft_strcpy(write_pos, sep);
		i++;
	}
	return (joined);
}

// int main(void)
// {
//     char *array[] = {"Hello", "world", "this", "is", "42"};
//     char *sep = ", ";
//     char *result;

//     result = ft_strjoin(5, array, sep);
//     if (!result)
//         return (1);
//     printf("Joined : \"%s\"\n", result);
//     free(result);

//     result = ft_strjoin(0, array, sep);
//     if (!result)
//         return (1);
//     printf("Joined with size=0 : \"%s\"\n", result);
//     free(result);

//     return 0;
// }
