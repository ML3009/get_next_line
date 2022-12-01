/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:31:13 by mvautrot          #+#    #+#             */
/*   Updated: 2022/12/01 16:18:30 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*appels successifs a la fonction 
lire integralite du fichier texte par le descripteur de fichier une ligne a la fois
retourner ligne qui vient d etre lue - si plus rien retourner NULL
Fonction doit se comporter correctement lorsquelle lit un fichier ou ou elle lit sur entree standard
Retourner la ligne qui a ete lue suivie d un \n SAUF si on a atteint la fin du fichier et que ce dernier
ne se termine pas par un \n*/


/*int read(int fd, char *buf, size_t nb_octet);
 lit nb_octets de donnees dans le fichier de descripteur fd et les place dans la zone pointee par buf
Cette zone doit donc etre au moins de taille nb_octet
Lit 50 octet et met les dans zone. la valeur de retour est le nombre effectif d octets transferes ou - 1 si erreur.
la fin de fichier est detecte en comparant l'offst du fichier, cad position caractere courant avec sa taille.
il ny a aucun indicuateur uo caractere special dans le fichier qui indique sa fin donc read retourn 0 si fin de fichier*/

#include "get_next_line.h"

char    *ft_read_line(int fd, char *line, char *buf);
char    *ft_check_line(char *line);

char    *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE + 1];
    char    *line;
    
    printf("ok fonction\n");
    line = NULL;
    if (fd < 0/*|| fd > 1024 */|| BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        printf("cas erreur 1");
        return (NULL);
    }
    printf("test\n");
    line = ft_read_line(fd, line, buf);
    printf("line ok");
    if (line[0] == '\0')
    {
        free(line);
        printf("free ok");
        return (NULL);
    }
    return (line);
}

char    *ft_read_line(int fd, char *line, char *buf)
{
    int ret;
    
    ret = 1;
    printf("entree read ligne\n");
    line = ft_strjoin(line, buf);
    while (ret != 0 && !ft_strchr(line, '\n'))
    {
        printf("boucle readline\n");
        ret = read(fd, buf, BUFFER_SIZE);
        printf("cc");
        buf[ret] = '\0';
        line = ft_strjoin(line, buf);/*ajouter a line le nouveau buf*/
        if (line == NULL)
        printf("cas d erreur read\n");
        return (NULL);
        
    }
    /*dans le cas ou nous avons trouve un \n, que faire du buf et de la line?*/
    if (ft_strchr(line, '\n'))//if nous avons trouve un \n
    {
        printf("entree 2 read\n");
        //buf = ft_next_line(line, buf);
        line = ft_check_line (line);
        //traiter le buf//
        //traiter la line//
    }
    printf("read ok\n");
    return (line);
}


/*char    ft_next_line(char *line, char *buf)
{
    int i;
    int j;

    i = 0;
    while (line[i] && line[i] != '\n')
        i++;
    i++;
    j = 0;
    while (line[i])
    {
        
    }


}*/

char *ft_check_line(char *line)
{
    int i;

    i = 0;
    while (line[i] && line[i] != '\n')
            i++;
    i++; 
    line [i] = '\0';
    return (line);
}

