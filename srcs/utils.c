/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:59:53 by msharifi          #+#    #+#             */
/*   Updated: 2022/07/08 16:32:19 by msharifi         ###   ########.fr       */
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
