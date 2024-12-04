/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:49:05 by yel-alja          #+#    #+#             */
/*   Updated: 2024/12/03 19:50:24 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*p;
	const unsigned char	*pt;
	size_t				i;

	p = (unsigned char *)dst;
	pt = (const unsigned char *)src;
	i = 0;
	if (!p && !pt)
		return (NULL);
	while (i < n)
	{
		p[i] = pt[i];
		i++;
	}
	return (dst);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc(len1 + len2 + 1);
	if (!result)
	{
		return (NULL);
	}
	if (s1)
		ft_memcpy(result, s1, len1);
	ft_memcpy(result + len1, s2, len2 + 1);
	free(s1);
	return (result);
}

char	*ft_strdup(char *s)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	str = malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
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
		return (NULL);
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
