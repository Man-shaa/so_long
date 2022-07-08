/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:25:42 by msharifi          #+#    #+#             */
/*   Updated: 2022/07/08 19:50:43 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(char **map)
{
	size_t	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

int	line_count(char *access_path)
{
	int		line_count;
	int		fd;
	char	*line;

	line_count = 0;
	fd = open(access_path, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Open failed !\n", 14);
		return (0);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

void	fill_map(t_data *data)
{
	char	*line;
	int		row;
	int		column;
	int		i;

	i = 0;
	row = 0;
	column = 0;
	line = get_next_line(data->map.fd);
	while (line != NULL)
	{
		data->map.map[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!(data->map.map[row]))
			return (free_map(data->map.map));
		while (line[i] != '\0' && line[i] != '\n')
			data->map.map[row][column++] = line[i++];
		column = 0;
		row++;
		i = 0;
		free(line);
		line = get_next_line(data->map.fd);
	}
	data->map.map[row] = NULL;
}

int	initialise_map(char *path, t_data *data)
{
	data->map.count_c = 0;
	data->map.count_p = 0;
	data->map.count_e = 0;
	data->map.collected = 0;
	data->map.path = path;
	data->map.line_count = line_count(path);
	if (!data->map.line_count)
		return (0);
	data->map.can_exit = 0;
	data->img.height = IMG_SIZE;
	data->img.width = IMG_SIZE;
	return (1);
}

int	create_map(char *path, t_data *data)
{
	if (!(initialise_map(path, data)))
		return (0);
	data->map.map = ft_calloc((data->map.line_count + 1), sizeof(char *));
	if (!(data->map.map))
		return (0);
	data->map.fd = open(path, O_RDONLY);
	if (data->map.fd < 0)
	{
		write(2, "Open failed !\n", 15);
		return (0);
	}
	fill_map(data);
	data->map.line_len = ft_strlen(data->map.map[0]);
	close(data->map.fd);
	return (1);
}
