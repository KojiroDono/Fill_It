/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:02:20 by auguyon           #+#    #+#             */
/*   Updated: 2018/12/12 17:53:30 by auguyon          ###   ########.fr       */
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
	new_tab[17] = '\0';	
	return (tmp);
}

void	first_hashtag(char **tab)
{
	int	d;
	int	i;
	int j;

	i = 0;
	j = 0;
	d = 0;
	while (tab[i])	
	{
		while (tab[i][d] != '#')
			d++;
		while (tab[i][j])
		{
			if (tab[i][j] == '#')
			{
				if (tab[i][j + 1] == '#' && tab[i][j + 3] == '#' && tab[i][j + 4] == '#' )
					d--;
				tab[i][j] = '.';
				tab[i][j - d] = '#';
			}
			j++;
		}
		d = 0;
		j = 0;
		i++;
	}
	tab[i] = 0;
}

char	**parse_tab(char *tab, int nb_tetra)
{
	char	**new_tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(new_tab = (char**)malloc(sizeof(new_tab) * nb_tetra + 1)))
		return (0);
	while (i < nb_tetra)
	{
		new_tab[i++] = del_eol(tab + j);
		j += 21;
	}
	i = 0;
	first_hashtag(new_tab);
	ft_putmultistr(new_tab);
	return (new_tab);
}
