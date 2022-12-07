/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:14:36 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/07 09:00:05 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_read_line(fd, line, buf);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*ft_read_line(int fd, char *line, char *buf)
{
	int	ret;

	ret = 1;
	line = ft_strjoin(line, buf);
	while (ret > 0 && !ft_strchr(line, '\n'))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		line = ft_strjoin(line, buf);
		if (line == NULL)
			return (NULL);
	}
	if (ft_strchr(line, '\n'))
		line = ft_check_line(line);
	return (line);
}

char	*ft_check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	i++;
	line [i] = '\0';
	return (line);
}