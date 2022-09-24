/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:13:13 by msharifi          #+#    #+#             */
/*   Updated: 2022/09/23 22:02:00 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_window(t_data *data)
{
	data->window_width = IMG_SIZE * data->map.line_len;
	data->window_height = IMG_SIZE * data->map.line_count;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->window_width,
			data->window_height, "Dofus 1.8");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (0);
	}
	return (1);
}

int	init_images(t_data *data)
{
	data->img.ground = mlx_xpm_file_to_image(data->mlx_ptr, GROUND,
			&data->img.width, &data->img.height);
	if (!data->img.ground)
		return (0);
	data->img.exit = mlx_xpm_file_to_image(data->mlx_ptr, EXIT,
			&data->img.width, &data->img.height);
	if (!data->img.exit)
		return (0);
	data->img.player_right = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_RIGHT,
			&data->img.width, &data->img.height);
	if (!data->img.player_right)
		return (0);
	data->img.player_left = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER_LEFT,
			&data->img.width, &data->img.height);
	data->img.wall = mlx_xpm_file_to_image(data->mlx_ptr, WALL,
			&data->img.width, &data->img.height);
	if (!data->img.wall)
		return (0);
	data->img.item = mlx_xpm_file_to_image(data->mlx_ptr, ITEM,
			&data->img.width, &data->img.height);
	if (!data->img.item)
		return (0);
	return (1);
}

void	loop_hook(t_data data)
{
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, ClientMessage, LeaveWindowMask,
		&handle_btnrealease, &data);
	mlx_loop(data.mlx_ptr);
}

void	loop_images(t_data data)
{
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, ClientMessage, LeaveWindowMask,
		&handle_btnrealease, &data);
	mlx_loop(data.mlx_ptr);
}
