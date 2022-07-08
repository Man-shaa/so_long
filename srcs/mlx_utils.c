/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:13:13 by msharifi          #+#    #+#             */
/*   Updated: 2022/07/08 15:01:14 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, "un debut de so_long");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (MLX_ERROR);
	}
	return (1);
}

void	init_images(t_data *data)
{
	data->img.ground = mlx_xpm_file_to_image(data->mlx_ptr, GROUND,
			&data->img.width, &data->img.height);
	data->img.exit = mlx_xpm_file_to_image(data->mlx_ptr, EXIT,
			&data->img.width, &data->img.height);
	data->img.player = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER,
			&data->img.width, &data->img.height);
	data->img.wall = mlx_xpm_file_to_image(data->mlx_ptr, WALL,
			&data->img.width, &data->img.height);
	data->img.item = mlx_xpm_file_to_image(data->mlx_ptr, ITEM,
			&data->img.width, &data->img.height);
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

void	destroy_images(t_data data)
{
	if (data.img.wall)
		mlx_destroy_image(data.mlx_ptr, data.img.wall);
	if (data.img.ground)
		mlx_destroy_image(data.mlx_ptr, data.img.ground);
	if (data.img.player)
		mlx_destroy_image(data.mlx_ptr, data.img.player);
	if (data.img.exit)
		mlx_destroy_image(data.mlx_ptr, data.img.exit);
	if (data.img.item)
		mlx_destroy_image(data.mlx_ptr, data.img.item);
	if (data.mlx_ptr)
		mlx_destroy_display(data.mlx_ptr);
	data.mlx_ptr = NULL;
}
