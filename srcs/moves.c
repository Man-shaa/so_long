/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:35:55 by msharifi          #+#    #+#             */
/*   Updated: 2022/09/23 22:06:20 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_next_tile(t_data *data, char direction, char tile)
{
	if ((direction == 'w')
		&& (data->map.map[data->player.p_x - 1][data->player.p_y]
		== tile))
		return (1);
	else if ((direction == 'a')
		&& (data->map.map[data->player.p_x][data->player.p_y - 1]
		== tile))
		return (1);
	else if ((direction == 's')
		&& (data->map.map[data->player.p_x + 1][data->player.p_y]
		== tile))
		return (1);
	else if ((direction == 'd')
		&& (data->map.map[data->player.p_x][data->player.p_y + 1]
		== tile))
		return (1);
	else
		return (0);
}

void	check_item_next_tile(t_data *data, char direction)
{
	if ((direction == 'w')
		&& (data->map.map[data->player.p_x - 1][data->player.p_y] == 'C'))
		data->map.collected += 1;
	else if ((direction == 'a')
		&& (data->map.map[data->player.p_x][data->player.p_y - 1] == 'C'))
		data->map.collected++;
	else if ((direction == 's')
		&& (data->map.map[data->player.p_x + 1][data->player.p_y] == 'C'))
		data->map.collected++;
	else if ((direction == 'd')
		&& (data->map.map[data->player.p_x][data->player.p_y + 1] == 'C'))
		data->map.collected++;
}

int	end_game(t_data *data)
{
	if (data->map.can_exit == 1)
	{
		ft_putstr_fd("Well done, you won in [", 1);
		ft_putnbr_fd(data->player.move_count, 1);
		ft_putstr_fd("] moves !\n", 1);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		return (1);
	}
	return (0);
}

void	move_player(t_data *data, char direction)
{
	if (check_next_tile(data, direction, '1')
		|| (check_next_tile(data, direction, 'E') && data->map.can_exit == 0))
		return ;
	data->player.move_count++;
	check_item_next_tile(data, direction);
	if (data->map.count_c == data->map.collected)
		data->map.can_exit = 1;
	data->map.map[data->player.p_x][data->player.p_y] = '0';
	if (direction == 'w')
		data->player.p_x--;
	else if (direction == 's')
		data->player.p_x++;
	else if (direction == 'a')
		data->player.p_y--;
	else if (direction == 'd')
		data->player.p_y++;
	if ((data->map.can_exit == 1)
		&& (data->map.map[data->player.p_x][data->player.p_y] == 'E'))
	{
		end_game(data);
		return ;
	}
	data->map.map[data->player.p_x][data->player.p_y] = 'P';
}
