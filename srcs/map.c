/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:25:42 by msharifi          #+#    #+#             */
/*   Updated: 2022/07/08 12:15:04 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(char **map)
{
	size_t	i;

	i = 0;
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
		write(2, "Open failed !\n", 15);
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

void	initialise_map(char *path, t_data *data)
{
	data->map.count_c = 0;
	data->map.count_p = 0;
	data->map.count_e = 0;
	data->map.collected = 0;
	data->map.path = path;
	data->map.line_count = line_count(path);
	data->map.can_exit = 0;
	data->img.height = IMG_SIZE;
	data->img.width = IMG_SIZE;
}

void	create_map(char *path, t_data *data)
{
	initialise_map(path, data);
	data->map.map = malloc(sizeof(char *) * (data->map.line_count + 1));
	if (!(data->map.map))
		return ;
	data->map.fd = open(path, O_RDONLY);
	if (data->map.fd < 0)
	{
		write(2, "Open failed !\n", 15);
		return ;
	}
	fill_map(data);
	data->map.line_len = ft_strlen(data->map.map[0]);
	close(data->map.fd);
}
