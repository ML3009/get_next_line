/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainGNLv2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:11:13 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/07 08:58:02 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"
int main(void)
{
	int		fd;
	char	*line;

	//fd = open("txt.txt", O_RDONLY);
    fd = 1;
	while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line); 
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
