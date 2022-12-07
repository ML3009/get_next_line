/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:10:07 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/07 11:35:28 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *line, char *buf)
{
	char	*tab;
	char	*new;
	int		size;
	int		i;

	i = 0;
	size = (ft_strlen(line) + ft_strlen(buf));
	tab = malloc (sizeof(char) * (size + 1));
	new = tab;
	if (!new)
		return (NULL);
	while (line && line[i])
	{
		tab[i] = line[i];
		i++;
	}
	while (*buf)
	{
		tab[i++] = *buf++;
	}
	tab[size] = '\0';
	free (line);
	return (new);
}

char	*ft_strchr(char *line, int c)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] != (char)c))
	{
		i++;
	}
	if (line[i] == (char)c)
		return ((char *)line + i);
	else
		return (NULL);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}
