/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml <ml@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:11:13 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/02 09:26:43 by ml               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

int main(void)
{
	int		fd;
	char	*line;

	fd = 0;
	fd = open("txt.txt", O_RDONLY);
	while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        printf("%s", line);
        free(line); // si pa free le pointeur sera ecrase a chaque fois dans la boucle. tt malloc qui n est pas free  est  leak.
    }
    return (0);
} 

/*int    main(int argc, char **argv)
{
    int    fd;
    char    *readed;

    if (argc == 0)
        return (0);
    if (fd < 0 || fd == -1)
        return (0);
    fd = open(argv[1], O_RDONLY);
    while (1)
    {
        readed = get_next_line(fd);
        printf("%s\n", readed);
        if (!readed)
            break ;
    }
    return (0);
}*/
