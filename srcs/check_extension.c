/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:25:12 by msharifi          #+#    #+#             */
/*   Updated: 2022/09/23 22:02:00 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_extension(char *path)
{
	int		fd;
	size_t	len;

	len = ft_strlen(path);
	if (open(path, __O_DIRECTORY) >= 0)
	{
		fd = open(path, __O_DIRECTORY);
		close(fd);
		return (0);
	}
	else
	{
		fd = open(path, O_RDONLY);
		close(fd);
		if (path[len - 4] != '.' || path[len - 3] != 'b'
			|| path[len - 2] != 'e' || path[len - 1] != 'r')
			return (0);
	}
	return (1);
}
