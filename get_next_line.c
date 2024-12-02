/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 09:46:13 by yel-alja          #+#    #+#             */
/*   Updated: 2024/12/02 17:55:21 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, ssize_t end)
{
	char	*str;
	ssize_t	i;

	if (!s)
		return (NULL);
	str = malloc(end + 1);
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

char	*ft_strchr(char *s, int c)
{
	unsigned int	i;
	char			y;
	char			*p;

	y = (char)c;
	i = 0;
	if (!s)
	{
		s = malloc(1);
		s = "";
	}
	while (s[i])
	{
		if (s[i] == y)
		{
			p = (char *)&s[i + 1];
			return (p);
		}
		i++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	char		*tmp;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !(ft_strchr(buffer, '\n')))
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (NULL);
		buffer = ft_strjoin(buffer, buff);
	}
	line = find_line(buffer);
	tmp = ft_strdup(ft_strchr(buffer, '\n'));
	free(buffer);
	buffer = ft_strdup(tmp);
	return (free(tmp), line);
}
