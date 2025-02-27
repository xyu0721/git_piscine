/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srahman <srahman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:12:53 by srahman           #+#    #+#             */
/*   Updated: 2025/02/22 23:48:24 by srahman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 4096
# define DEFAULT_DICT "numbers.dict"

typedef struct s_dict_entry
{
	unsigned long long	number;
	char				*word;
	struct s_dict_entry	*next;
}	t_dict_entry;

/* main functions */
int					process_number(char *number, t_dict_entry *dict);
t_dict_entry		*read_dictionary(char *dict_path);
void				print_number_word(unsigned long long num,
						t_dict_entry *dict);
int					process_three_digits(unsigned long long num,
						t_dict_entry *dict);

/* dictionary functions */
t_dict_entry		*create_entry(unsigned long long number, char *word);
void				free_dictionary(t_dict_entry *dict);
int					is_valid_number(char *str);
void				add_entry(t_dict_entry **dict, t_dict_entry *new_entry);

/* parser functions */
t_dict_entry		*parse_line(char *line);
void				process_buffer(char *buffer, t_dict_entry **dict);

/* utility functions */
void				ft_putstr(char *str);
int					ft_strlen(char *str);
char				*ft_strdup(char *src);
unsigned long long	ft_atoi(char *str);
char				*ft_itoa(unsigned long long n);

/* error handling functions */
void				print_error(void);
void				print_dict_error(void);
int					process_and_free(char *number, t_dict_entry *dict,
						int is_stdin);

#endif 