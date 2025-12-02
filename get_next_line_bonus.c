/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mezahir <mezahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:37:41 by mezahir           #+#    #+#             */
/*   Updated: 2025/12/02 23:33:28 by mezahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char    *read_until_newline(int fd,char *str)
{
    char *buffer;
    int count_rd;
    
    buffer = malloc((size_t) BUFFER_SIZE + 1);
    if(!buffer)
        return(NULL);
    count_rd = 1;
     while(!(ft_search(str,'\n')) && count_rd != 0)
    {
    count_rd = read(fd,buffer,BUFFER_SIZE);
    if(count_rd < 0)
    {
        free(buffer);
        free(str);
        return(NULL);
    }
    buffer[count_rd] = '\0';
    str[fd] = ft_concat_str(str[fd],buffer);
    }
    free(buffer);
    return(str[fd]);
}
char *ft_line(char *str)
{
    char *line;
    int i;
    if(!str[i])
        return (NULL);
    i = 0;
    while(str[i] && !(ft_search(str,'\n')) )
        i++;
    if(str[i] == '\n')
        i++;
    line = malloc(i + 1);
    if(!line)
        return(NULL);
    i = 0;
    while(str[i] && !(ft_search(str[i],'\n')) )
    {
        line[i] = str[i];
        i++;
    }
    if(str[i] == '\n')
    {
        line[i] = '\n';
        i++;
    }
    line[i] = '\0';
    return(line);
}
char *ft_rest(char *str)
{
    int i;
    int j;
    char *rest;
    
    i = 0;
    if(!str)
        return(NULL);
    while(str[i] && !(ft_search(str,'\n')) )
        i++;
    if(str[i] == '\0')
    {
        free(str);
        return (NULL);
    }
    rest = malloc(ft_strlen(str) - i);
    if(!rest)
        return (NULL);
    j = 0;
    if(str[i] == '\n')
        i++;
    while(str[i])
       rest[j++] = str[i++];
    rest[j] = '\0';
    free(str);
    return (rest);
}

char *get_next_line_bonus(int fd)
{
    static char *str[1024];
    char *line;
    if(fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    str[fd] = read_until_newline(fd,str[fd]);
    line = ft_line(str[fd]);
    str[fd] = ft_rest(str[fd]);
    return (line);
}
