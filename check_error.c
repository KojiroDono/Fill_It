/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:45:41 by auguyon           #+#    #+#             */
/*   Updated: 2018/12/11 11:03:52 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		print_error(int i)
{
	if (i == -1)
		write(2, "Error\n", 6);
	return (0);
}

int     check_error(char *str)
{
    int i;
    int n;
    int d;
    int t;

    i = 0;
    n = 0;
    d = 0;
    t = 0;
    while (str[i] == '\n' || str[i] == '#' || str[i] == '.')
    {
        if (str[i] != '\n' || str[i] != '#' || str[i] != '.')
            return (-1);
        if (str[i] == '#')
            d++;
        if (str[i] == '\n')
            n++;
        if (d == 4 && (n == 4 || n == 3) && (str[i] == '\n' || str[i] == '\0'))
        {
            t++;
            d = 0;
            n = 0;
        }
        if (d != 4 && (n != 4 || n != 3) && (str[i] != '\n' || str[i] != '\0'))
            return (-1);
        i++;
    }
    return (0);
}

int     check_all(char *str)
{
    int    o;
    int    len;
	
	o = 0;
	len = ft_strlen(str);
	while (o < len)
    {
        if (!check_error(str + o))
            return (-1);
        o += 21;
    }
    return (1);
}
