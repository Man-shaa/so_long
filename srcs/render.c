/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:31:18 by msharifi          #+#    #+#             */
/*   Updated: 2022/09/23 22:02:00 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	parse_chars(t_data *data, int width, int i, int j)
{
	char	*moves;

	moves = ft_itoa(data->player.move_count);
	if (data->map.map[i][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.wall, width, i * IMG_SIZE);
	if (data->map.map[i][j] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.ground, width, i * IMG_SIZE);
	else if (data->map.map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.player_right, width, i * IMG_SIZE);
	else if (data->map.map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.exit, width, i * IMG_SIZE);
	else if (data->map.map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.item, width, i * IMG_SIZE);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 30, 0xFEFEFF, "MOVES : ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 80, 30, 0xFEFEFF, moves);
	free(moves);
}

int	render(t_data *data)
{
	int		i;
	size_t	j;
	int		width;

	if (data->win_ptr == NULL)
		return (MLX_ERROR);
	i = 0;
	j = 0;
	width = 0;
	while (data->map.map[i])
	{
		while (data->map.map[i][j] && data->map.map[i][j] != '\n')
		{
			parse_chars(data, width, i, j);
			width += IMG_SIZE;
			j++;
		}
		j = 0;
		width = 0;
		i++;
	}
	return (1);
}
