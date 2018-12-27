/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:45:41 by auguyon           #+#    #+#             */
/*   Updated: 2018/12/27 11:24:31 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     print_error()
{
    write(2, "Error\n", 6);
    return (0);
}

int     check_good_pattern(char *str)
{
    int i;
    int point;
    int cross;
    int nret;

    i = -1;
    point = 0;
    cross = 0;
	nret = 0;
    while (str[++i])
    {
        if (str[i] == '.')
            point++;
        if (str[i] == '#')
            cross++;
        if (str[i] == '\n')
            nret++;
    }
    if (cross != 4 || point != 12)
        return (0);
    if ((nret == 4 && str[20] == '\n' && str[21] == '\0') ||
            ((nret == 5 && str[20] == '\n' && str[21] == '\n')))
        return (1);
    return (1);
}

int     check_link_tetra(char *str)
{
    int i;
    int link;

    i = -1;
    link = 0;
    while (str[++i])
    {
        if (str[i] == '#')
        {
            if (str[i + 1] == '#' && str[i + 1])
                link++;
            if (str[i + 5] == '#' && str[i + 5])
                link++;
            if (str[i - 1] == '#' && str[i - 1])
                link++;
            if (str[i - 5] == '#' && str[i - 5])
                link++;
        }
    }
    if (link == 6 || link == 8)
        return (1);
    return (0);
}

int     check_tetra_is_good(char *tab)
{
    size_t  i;
    size_t  l;
    int t;
    
    t = 0;
    i = 0;
    l = ft_strlen(tab);
    while (i < l)
    {
        check_good_pattern(tab + i);
        check_link_tetra(tab + i);
            t++;
        i = i + 21;
    }
    return (t);
}
