/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:19:50 by msharifi          #+#    #+#             */
/*   Updated: 2022/07/06 17:40:16 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>

# define BUFFER_SIZE 10

size_t	ft_strlen(char *str);
int		ft_strchr(char *str);
char	*ft_strcpy(char *s1, char *s2);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*is_remaining(char *str, char *buffer);
char	*get_line(char *str, char *buffer, char *line, int fd);
char	*get_remaining(char *str);
char	*get_next_line(int fd);

#endif
