/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:19:54 by msharifi          #+#    #+#             */
/*   Updated: 2022/05/20 20:36:13 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen((char *)s) <= start)
		return (ft_strdup(""));
	if (len > start && start != 1)
		str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) - start + 1));
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[start] && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	*is_remaining(char *str, char *buffer)
{
	if (!str || str[0] == '\0')
		return (NULL);
	buffer = ft_strjoin(buffer, str);
	if (!buffer)
		return (NULL);
	return (buffer);
}

char	*get_line(char *str, char *buffer, char *line, int fd)
{
	int		byte;

	byte = 1;
	while (ft_strchr(str) == -1 && byte != 0)
	{
		byte = read(fd, str, BUFFER_SIZE);
		if (byte < 0 || str[0] == '\0')
			return (NULL);
		if (byte == 0)
		{
			str[0] = '\0';
			return (buffer);
		}
		str[byte] = '\0';
		buffer = ft_strjoin(buffer, str);
	}
	byte = 0;
	while (buffer[byte] && buffer[byte] != '\n')
		byte++;
	if (buffer[byte] == '\n')
	{
		line = ft_substr(buffer, 0, ft_strchr(buffer) + 1);
		return (free(buffer), line);
	}
	return (buffer);
}

char	*get_remaining(char *str)
{
	int		i;
	int		j;
	char	*remaining;

	i = 0;
	j = 0;
	remaining = NULL;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (NULL);
	remaining = malloc(ft_strlen(str) - i * 1);
	if (!remaining)
		return (NULL);
	i++;
	while (str[i])
		remaining[j++] = str[i++];
	remaining[j] = '\0';
	ft_strcpy(str, remaining);
	return (free(remaining), str);
}

char	*get_next_line(int fd)
{
	static char	str[BUFFER_SIZE + 1] = {0};
	char		*buffer;
	char		*line;

	buffer = NULL;
	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1023)
		return (NULL);
	buffer = is_remaining(str, buffer);
	line = get_line(str, buffer, line, fd);
	if (!line)
		return (NULL);
	get_remaining(str);
	return (line);
}
