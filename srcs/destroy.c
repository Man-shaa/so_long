/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:33:09 by msharifi          #+#    #+#             */
/*   Updated: 2022/07/28 12:41:25 by msharifi         ###   ########.fr       */
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

void	destroy_images(t_data *data)
{
	if (data->img.wall)
		mlx_destroy_image(data->mlx_ptr, data->img.wall);
	if (data->img.ground)
		mlx_destroy_image(data->mlx_ptr, data->img.ground);
	if (data->img.player_left)
		mlx_destroy_image(data->mlx_ptr, data->img.player_left);
	if (data->img.player_right)
		mlx_destroy_image(data->mlx_ptr, data->img.player_right);
	if (data->img.exit)
		mlx_destroy_image(data->mlx_ptr, data->img.exit);
	if (data->img.item)
		mlx_destroy_image(data->mlx_ptr, data->img.item);
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
