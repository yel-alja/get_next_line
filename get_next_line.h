/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alja <yel-alja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 09:53:32 by yel-alja          #+#    #+#             */
/*   Updated: 2024/12/02 17:59:53 by yel-alja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined BUFFER_SIZE && BUFFER_SIZE < 0
#undef BUFFER_SIZE
#define BUFFER_SIZE 0
#endif

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif


char    *get_next_line(int fd);
char    *rea_fun(int fd , char *buffer);
char    *ft_strdup(char *str);
ssize_t new_line(char *str);
char    *find_line(char *str);
size_t  ft_strlen(char *str);
char    *ft_strjoin(char *s1, char *s2);
void    *ft_memcpy(void *dst, const void *src, size_t n);








#endif
