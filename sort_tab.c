/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:02:20 by auguyon           #+#    #+#             */
/*   Updated: 2019/01/05 17:38:54 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static char	*del_new_line(char *tab)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(str = (char*)malloc(sizeof(*str) * 17)))
		if (!print_error(-42))
			return (NULL);
	while (i < 21)
	{
		if (tab[i] == '\n')
			i++;
		str[j] = tab[i];
		i++;
		j++;
		if (j == 17)
			str[j] = '\0';
	}
	return (str);
}

static void	check_spe_tetra(char *tab, int j, int *d)
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

static void	moove_tetra_to_left(char **tab, int nb_tetra)
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

char		**sort_tab(char *tab, t_fi *s)
{
	char	**new_tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(new_tab = (char**)malloc(sizeof(new_tab) * s->nb_tetra + 1)))
	{
		free_struct(s);
		print_error(-42);
		return (NULL);
	}
	while (i < s->nb_tetra)
	{
		new_tab[i++] = del_new_line(tab + j);
		j += 21;
	}
	new_tab[s->nb_tetra] = 0;
	moove_tetra_to_left(new_tab, s->nb_tetra);
	free(tab);
	return (new_tab);
}
