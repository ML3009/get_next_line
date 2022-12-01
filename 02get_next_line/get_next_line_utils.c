/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:31:17 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/01 13:27:26 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(char *str)
{
    size_t i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_strjoin(char *line, char *buf)
{
    char    *tab;
    size_t  i;
    size_t  j;

    i = 0;
    j = 0;
    tab = malloc (sizeof(char) * (ft_strlen((char *)line) + ft_strlen((char *)buf) + 1));
    if(!tab)
        return (NULL);
    if (!line || !buf)
        return (NULL);
    {
        while(line[i])
        {
            tab [i] = line[i];
            i++;
        }
        while (buf[j])
        {
            tab[i + j] = buf[j];
            j++;
        }
        tab[i + j] = '\0';
        
        return (tab);
    }   
}

char    *ft_strchr(char *line, int c)
{
    char *ptr;
    ptr = line;

    while (*ptr && *ptr != (char)c)
        ptr++;
    if (*ptr == (char)c)
            return (ptr);
    else
        return (NULL);
}
