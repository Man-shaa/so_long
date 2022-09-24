/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:33:09 by msharifi          #+#    #+#             */
/*   Updated: 2022/09/24 13:02:19 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	if (map)
		free(map);
	map = NULL;
}

void	destroy_images(t_data *data)
{
	if (data->img.wall)
		mlx_destroy_image(data->mlx_ptr, data->img.wall);
	data->img.wall = NULL;
	if (data->img.ground)
		mlx_destroy_image(data->mlx_ptr, data->img.ground);
	data->img.ground = NULL;
	if (data->img.player_left)
		mlx_destroy_image(data->mlx_ptr, data->img.player_left);
	data->img.player_left = NULL;
	if (data->img.player_right)
		mlx_destroy_image(data->mlx_ptr, data->img.player_right);
	data->img.player_right = NULL;
	if (data->img.exit)
		mlx_destroy_image(data->mlx_ptr, data->img.exit);
	data->img.exit = NULL;
	if (data->img.item)
		mlx_destroy_image(data->mlx_ptr, data->img.item);
	data->img.item = NULL;
}

int	destroy_all(t_data *data)
{
	destroy_images(data);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	free_map(data->map.map);
	return (0);
}
