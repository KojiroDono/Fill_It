/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:02:20 by auguyon           #+#    #+#             */
/*   Updated: 2018/12/28 15:05:41 by auguyon          ###   ########.fr       */
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

void	check_spe_tetra(char *tab, int j, int *d)
{
	if (tab[j + 1] == '#' && tab[j + 3] == '#' && tab[j + 4] == '#')
		(*d)--;
	else if (tab[j + 3] == '#' && tab[j + 4] == '#' && tab[j + 8] == '#')
		(*d)--;
	else if (tab[j + 2] == '#' && tab[j + 3] == '#' && tab[j + 4] == '#')
		*d = (*d) - 2;
	else if (tab[j + 4] == '#' && tab[j + 7] == '#' && tab[j + 8] == '#')
		(*d)--;
	else if (tab[j + 3] == '#' && tab[j + 4] == '#' && tab[j + 5] == '#')
		(*d)--;
	else if (tab[j + 3] == '#' && tab[j + 4] == '#' && tab[j + 7] == '#')
		(*d)--;
}

void	moove_tetra_to_left(char **tab, int nb_tetra)
{
	int	d;
	int	i;
	int j;

	i = 0;
	while (tab[i] && !(j = 0))
	{
		d = 0;
		while (tab[i][d] != '#')
			d++;
		check_spe_tetra(tab[i], d, &d);
		while (tab[i][j])
		{
			if (tab[i][j] == '#')
			{
				tab[i][j] = '.';
				tab[i][j - d] = '#';
			}
			j++;
		}
		if (nb_tetra == 1)
			return ;
		i++;
	}
}

char	**sort_tab(char *tab, int nb_tetra)
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
	new_tab[nb_tetra] = 0;
	moove_tetra_to_left(new_tab, nb_tetra);
	ft_strdel(&tab);
	return (new_tab);
}
