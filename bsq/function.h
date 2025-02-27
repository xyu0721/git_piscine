/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shizhou <shizhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:41:18 by shizhou           #+#    #+#             */
/*   Updated: 2025/02/26 22:12:37 by shizhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 4096

typedef struct s_map
{
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
	char	**map;
}t_map;

typedef struct s_dp_data
{
	int		**dp;
	t_map	*map;
	int		*max_info;
}	t_dp_data;

typedef struct s_row_info
{
	int		row;
	int		col;
	int		start;
	char	*buffer;
}t_row_info;

// parser.c
t_map	*parse_map(char *filename);
int		parse_map_header(char *buffer, t_map *map, int *i);
int		read_map_content(char *buffer, t_map *map, int i, int bytes);
int		allocate_map_row(t_map *map, t_row_info *info);
int		verify_map_end(char *buffer, int start, int bytes, int valid_rows);

// parser_utils.c
void	map_error(void);
void	free_map(t_map *map);
int		is_valid_char(char c, t_map *map);

// solver.c
void	solve_bsq(t_map *map);

// solver_utils.c
void	fill_map(t_map *map, int max_row, int max_col, int max_size);
void	init_dp(int **dp, t_map *map, int *max_info);
void	calculate_dp(int **dp, t_map *map, int *max_info);
void	free_dp(int **dp, int rows);

// help.c
int		parse_number(char *buffer, int *i, int num_end);
int		get_column_count(char *buffer, int *start, t_map *map);
int		validate_column_count(t_map *map, int col, int row);
int		process_map_row(char *buffer, t_map *map, int row, int *start);
int		parse_and_validate_map(char *buffer, t_map *map, int total_bytes);

// utils.c
int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		ft_min(int a, int b, int c);
int		fd_error(int fd);
int		get_line_length(char *buffer);

// utils2.c
void	print_map(t_map *map);
void	cleanup_map_on_error(char *buffer, t_map *map);

// map.c
int		open_file(char *filename);
char	*expand_buffer(char *buffer, char *tmp, int *total_bytes, int bytes);
char	*initialize_buffer(void);
char	*read_map_file(int fd, int *total_bytes);
t_map	*initialize_map(void);

#endif
