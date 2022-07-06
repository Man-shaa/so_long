/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:25:42 by msharifi          #+#    #+#             */
/*   Updated: 2022/07/06 17:36:05 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


int	line_count(char *access_path)
{
	int		line_count;
	int		fd;
	char	*line;

	line_count = 0;
	fd = open(access_path, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Open failed !", 14);
		return (0);
	}
	
}

int	create_map(t_data *data)
{

}