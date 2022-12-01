/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:31:10 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/01 16:03:26 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


#ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 5
#endif

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char    *get_next_line(int fd); 
char    *ft_read_line(int fd, char *line, char *buf);
char    *ft_check_line(char *line);
char    *ft_strjoin(char *line, char *buf);
char    *ft_strchr(char *line, int c);
size_t  ft_strlen(char *str);


#endif