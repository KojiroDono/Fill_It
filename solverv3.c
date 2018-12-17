/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solverv3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:35:23 by auguyon           #+#    #+#             */
/*   Updated: 2018/12/17 15:43:07 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int 	check_place(char **tab, t_fi s)
{
	int i = 0;
	int j = 0;

	while (tab[i][j])
	{
		while (tab[i][j] != '#' && tab[i][j])
		{
			if (j % 4 == 0)
			{
				s.i++;
				if (tab[i][j + 1] == '#')
					s.j = 0;
			}
			j++;
		}
		if (tab[i][j] == '#')
		{
			if (ft_isupper(map[s.i][s.j]) || map[s.i][s.j])
				return (0);
			if (tab[i][j + 1] == '#')
				s.j = 0;
		}
	}
	return (1);
}

int		check_map(t_fi lst)
{
	while (ft_isupper(map[lst.ia][lst.ja]))
	{
		if (map[lst.ia][lst.ja])
		{
			lst.ia++;
			lst.ja = 0;
		}
		lst.ja++;
	}
	if (!ft_isupper(map[lst.ia][lst.ja]) && map[lst.ia][lst.ja])
		return (1);
	return (0);
}

int		solver(char **tab, t_fi s)
{
	int 	i;
	int 	j;
	int		i_tmp;
	int		j_tmp;

	i = 0;
	j = 0;
	if (s.nb_tetra == 0)
		return (1);
	while (tab[i][j])
	{
		if (check_map(s))
		{
			i_tmp = s.i;
			j_tmp = s.j;
			if (!check_place(s))
			{
				s.j++;
				return (solver(tab, s));
			}
			while (tab[i][j])
			{
				while (tab[i][j] != '#' && tab[i][j])
				{
					if (j % 4 == 0)
					{
						i_tmp++;
						if (tab[i][j + 1] == '#')
							j_tmp = 0;
					}
					j++;
				}
				if (tab[i][j] == '#')
					map[i_tmp][j_tmp] = s.c;
			}
			s.i = 0;
			s.j = 0;
			if (solver(tab, s) == 1)
				return (1);
		}
	}
}
