/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 04:42:28 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/25 04:42:32 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	while (*charset != '\0')
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str != '\0')
	{
		if (!is_charset(*str, charset))
		{
			if (!in_word)
			{
				count++;
				in_word = 1;
			}
		}
		else
		{
			in_word = 0;
		}
		str++;
	}
	return (count);
}

char	*word_dup(char *start, char *end)
{
	int		len;
	char	*word;
	int		i;

	len = end - start;
	i = 0;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

void	fill_words(char **result, char *str, char *charset)
{
	int		i;
	char	*start;

	i = 0;
	while (*str != '\0')
	{
		if (!is_charset(*str, charset))
		{
			start = str;
			while (*str != '\0' && !is_charset(*str, charset))
				str++;
			result[i++] = word_dup(start, str);
		}
		else
		{
			str++;
		}
	}
	result[i] = NULL;
}

char	**ft_split(char *str, char *charset)
{
	int		word_count;
	char	**result;

	word_count = count_words(str, charset);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	fill_words(result, str, charset);
	return (result);
}

// #include <stdio.h>

// int main() {
//     char str[] = "Hello,,World! 42tokyo";
//     char charset[] = ", !";

//     char **words = ft_split(str, charset);
//     if (!words) {
//         printf("Memory allocation failed\n");
//         return 1;
//     }

//     for (int i = 0; words[i]; i++)
//         printf("Word %d: %s\n", i, words[i]);

//     // メモリ解放
//     for (int i = 0; words[i]; i++)
//         free(words[i]);
//     free(words);

//     return 0;
// }
