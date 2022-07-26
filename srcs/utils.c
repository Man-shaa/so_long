/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:59:53 by msharifi          #+#    #+#             */
/*   Updated: 2022/07/26 15:42:27 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_bzero(void *tab, size_t n)
{
	char	*str;

	str = tab;
	while (n > 0)
	{
		*str = '\0';
		str++;
		n--;
	}
}

void	ft_putstr_fd(char *str, int fd)
{
	int	len;

	len = ft_strlen(str);
	write(fd, str, len);
}

void	*ft_calloc(size_t nelem, size_t size)
{
	void	*tab;

	tab = malloc(size * nelem);
	if (!tab)
		return (NULL);
	ft_bzero(tab, (nelem * size));
	return (tab);
}

int	ft_strchr2(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (c);
		i++;
	}
	return (0);
}

int	destroy_all(t_data data)
{
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	free_map(data.map.map);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}