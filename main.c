/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:31:35 by msharifi          #+#    #+#             */
/*   Updated: 2022/07/07 18:02:04 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_data	data;
	create_map("maps/test_map.ber", &data);
	if (!(parsing(&data)))
	{
		write(2, "Map non conforme !\n", 19);
		return(free_map(data.map.map), 0);
	}
	init_window(&data);
	init_images(&data);
	render(&data);
	loop_hook(data);
	destroy_images(data);
	free(data.mlx_ptr);
	if (data.map.map)
		free_map(data.map.map);
	return (0);
}
