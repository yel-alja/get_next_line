/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:47:40 by yel-alja          #+#    #+#             */
/*   Updated: 2024/12/04 10:26:35 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char *s, ssize_t end)
{
	char	*str;
	ssize_t	i;

	if (!s)
		return (NULL);
	str = malloc(end + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && i <= end)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*find_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
			return (ft_substr(str, i));
		i++;
	}
	return (NULL);
}

char	*read_fun(char *buffer, char *buff, int fd)
{
	ssize_t	bytes_read;

	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (bytes_read > 0 && !(ft_strchr(buffer, '\n')))
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buff);
			free(buffer);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, buff);
	}
	free(buff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[max_fd];
	char		*buff;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	buffer[fd] = read_fun(buffer[fd], buff, fd);
	line = find_line(buffer[fd]);
	if (!line && buffer[fd] && *buffer[fd] != '\0')
	{
		line = ft_strdup(buffer[fd]);
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (line);
	}
	tmp = ft_strdup(ft_strchr(buffer[fd], '\n'));
	free(buffer[fd]);
	buffer[fd] = ft_strdup(tmp);
	return (free(tmp), line);
}
