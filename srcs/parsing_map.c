/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:21:49 by msharifi          #+#    #+#             */
/*   Updated: 2022/07/26 16:39:59 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_rect(t_data *data)
{
	int			line;
	size_t		row;
	size_t		len;

	row = 0;
	len = data->map.line_len;
	line = data->map.line_count;
	while (line != 0)
	{
		if (ft_strlen(data->map.map[row]) != len)
			return (0);
		line--;
		row++;
	}
	return (1);
}

int	is_btw_walls(t_data *data, int i)
{
	int	last_row;
	int	last_column;

	last_column = data->map.line_len - 1;
	last_row = data->map.line_count - 1;
	if (last_column < 0 || last_row < 0)
		return (0);
	while (data->map.map[0][i] != '\0' && data->map.map[0][i] != '\n'
		&& data->map.map[last_row][i] != '\0'
		&& data->map.map[last_row][i] != '\n')
	{
		if (data->map.map[0][i] != '1' || data->map.map[last_row][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < data->map.line_count)
	{
		if (data->map.map[i][0] != '1' || data->map.map[i][last_column] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	select_incrementation(char c, t_data *data)
{
	if (c == '0' || c == '1')
		return ;
	else if (c == 'E')
		data->map.count_e++;
	else if (c == 'P')
		data->map.count_p++;
	else if (c == 'C')
		data->map.count_c++;
}

int	is_valid(int row, int column, t_data *data)
{
	while (row < data->map.line_count)
	{
		while (data->map.map[row][column])
		{
			if (data->map.map[row][column] == '0'
				|| data->map.map[row][column] == '1'
				|| data->map.map[row][column] == 'P'
				|| data->map.map[row][column] == 'C'
				|| data->map.map[row][column] == 'E')
				select_incrementation(data->map.map[row][column], data);
			else
				return (0);
			column++;
		}
		row++;
		column = 0;
	}
	if (data->map.count_c < 1 || data->map.count_e != 1
		|| data->map.count_p != 1)
		return (0);
	return (1);
}

int	parsing(t_data *data)
{
	int	row;
	int	column;
	int	i;

	i = 0;
	row = 0;
	column = 0;
	if (!is_rect(data))
	{
		free_map(data->map.map);
		return (ft_putstr_fd("Map non rectangulaire !\n", 2), 0);
	}
	if (!is_btw_walls(data, i))
	{
		free_map(data->map.map);
		return (ft_putstr_fd("Map non conforme !\n", 2), 0);
	}
	if (!is_valid(row, column, data))
	{
		free_map(data->map.map);
		return (ft_putstr_fd("Il manque un element de la map !\n", 2), 0);
	}
	return (1);
}
