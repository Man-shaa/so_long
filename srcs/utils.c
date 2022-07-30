/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:59:53 by msharifi          #+#    #+#             */
/*   Updated: 2022/07/30 18:23:23 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_bzero(void *tab, int n)
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

void	fill(char *str, long long nb, int j)
{
	j--;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (j >= 0 && str[j] != '-')
	{
		str[j] = (nb % 10) + 48;
		nb /= 10;
		j--;
	}
}

char	*ft_itoa(int n)
{
	long long	nb;
	int			j;
	char		*str;

	nb = (long long)n;
	j = 0;
	if (nb <= 0)
		j++;
	while (n != 0)
	{
		n /= 10;
		j++;
	}
	str = ft_calloc(j + 1, 1);
	if (!str)
		return (NULL);
	str[j] = '\0';
	fill(str, nb, j);
	return (str);
}
