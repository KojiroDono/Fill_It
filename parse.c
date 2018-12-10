/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:02:20 by auguyon           #+#    #+#             */
/*   Updated: 2018/12/10 19:52:47 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*del_eol(char *tab)
{
	char	*new_tab;
	char	*tmp;
	int		i;

	i = 0;
	if (!(new_tab = (char*)malloc(sizeof(*new_tab) * 17)))
		return (0);
	tmp = new_tab;
	while (i < 4)
	{
		new_tab = ft_strncpy(new_tab, tab, 4);
		tab += 5;
		new_tab += 4;
		i++;
	}
	*new_tab = '\0';	
	return (tmp);
}

char	**parse_tab(char *tab, int nb_tetra)
{
	char	**new_tab = NULL;
	int		i;
	int		j;
	int		d;

	i = 0;
	j = 0;
	if (!(new_tab = (char**)malloc(sizeof(new_tab) * nb_tetra + 1)))
		return (0);
	d = 0;
	while (i < nb_tetra)
	{
		new_tab[i++] = del_eol(tab + j);
		j += 21;
	}
	i = 0;
	j = 0;
	while (new_tab[i])
	{
		while (new_tab[i][d] != '#')
			d++;
		while (new_tab[i][j])
		{
			if (new_tab[i][j] == '#')
			{
				if (new_tab[i][j + 1] == '#' && new_tab[i][j + 3] == '#' && new_tab[i][j + 4] == '#' )
					d--;
				new_tab[i][j] = '.';
				new_tab[i][j - d] = '#';
			}
			j++;
		}
		d = 0;
		j = 0;;
		i++;
	}
	new_tab[i] = 0;
//	ft_putmultistr(new_tab);
	return (new_tab);
}
