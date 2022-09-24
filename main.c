/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:31:35 by msharifi          #+#    #+#             */
/*   Updated: 2022/09/23 22:02:04 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	data = (t_data){0};
	if (ac != 2)
	{
		ft_putstr_fd("There isn't 2 arguments here !\n", 2);
		return (EXIT_FAILURE);
	}
	if (!(create_map(av[1], &data)) || !(parsing(&data)))
		return (EXIT_FAILURE);
	init_player_pos(&data);
	if (!init_window(&data) || !init_images(&data))
	{
		destroy_all(&data);
		return (EXIT_FAILURE);
	}
	render(&data);
	loop_hook(data);
	destroy_images(&data);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	free_map(data.map.map);
	return (0);
}

// 	- Ecrire le nombre direct dans la fenetre