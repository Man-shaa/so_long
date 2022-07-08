/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:31:35 by msharifi          #+#    #+#             */
/*   Updated: 2022/07/08 19:49:41 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_data	data;
	if (!(create_map("maps/test_map.ber", &data)) || !(parsing(&data)))
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
// 	- Choper directement la map en argument
// 	- Verifier quil y a que 2 arguments
// 	- Changer le visuel :	- les murs et la sortie
// 							- decoupage atour du personnage, de la sortie et des items
// 							- trouver des images des pov differents pour le presonnage selon ses mouvements
// 							- Pouvoir aller sur la sortie sans sortir si on a pas ramasse tous les items (?)
// 							- Trouver une image de vulbis plus petite : trop grande par rapport au personnage
// 	- Ecrire le nombre de pas sans printf
// 	- Ecrire le nombrede pas direct dans la fenetre (?)
// 	- Bonus (?)
// 	- Ennemi avec IA debile (?)