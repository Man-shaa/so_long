/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:24:32 by msharifi          #+#    #+#             */
/*   Updated: 2022/09/23 22:02:00 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	len;

	len = ft_strlen(str);
	write(fd, str, len);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar("0123456789"[n % 10]);
}

void	ft_print(char *str, int n, int fd)
{
	if (str != NULL)
		ft_putstr_fd(str, fd);
	if (n >= 0)
		ft_putnbr_fd(n, fd);
}
