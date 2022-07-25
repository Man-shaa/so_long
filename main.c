/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:31:35 by msharifi          #+#    #+#             */
/*   Updated: 2022/07/25 21:22:44 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;
	if (ac != 2)
		return (0);
	if (!(create_map(av[1], &data)) || !(parsing(&data)))
		return (0);
	init_player_pos(&data);
	init_window(&data);
	init_images(&data);
	render(&data);
	loop_hook(data);
	destroy_images(data);
	free(data.mlx_ptr);
	free_map(data.map.map);
	return (0);
}


// Manque :
//	- Verifier que c'est un fichier .ber et pas un document .ber
//	- Ecｒire des messages d'erreurs
// 							- trouver des images des pov differents pour le presonnage selon ses mouvements
// 	- Ecrire le nombre de pas sans printf
// 	- Ecrire le nombre direct dans la fenetre (?)
// 	- Bonus (?)
// 	- Ennemi avec IA debile (?)