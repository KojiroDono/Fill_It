/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solverv6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 12:17:42 by auguyon           #+#    #+#             */
/*   Updated: 2018/12/20 22:28:37 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		erase_last_tetra(t_fi *s)
{
	int i;
	int j;
	int one;

	i = 0;
	j = 0;
	one = 0;
	s->c--;
	s->nb_tetra++;
	while (s->map[i])
	{
		while (s->map[i][j])
		{
			if (s->map[i][j] == s->c && one == 0)
			{
				s->i = i;
				s->j = (j + 1);
				one++;
			}
			if (s->map[i][j] == s->c)
				s->map[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
		ft_putendl("tetra delete !");
		ft_putmultistr(s->map);
	return (1);
}

int		find_hashtag_n_return_pos(char *tab, int j, t_fi *s)
{
	while (tab[j] != '#' && tab[j])
	{
		if ((j + 1) % 4 == 0)
		{
			s->i++;
			if (tab[j + 1] == '#')
				s->j--;
			else if (tab[j + 3] == '#')
				s->j++;
		}
		j++;
	}
	return (j);
}

int		fill_map_w_tetra(char *tab, t_fi *s)
{
	int j;

	j = 0;
	while (tab[j])
	{
//		if ((j = find_hashtag_n_return_pos(tab, j, s)) >= 16)
//			break ;
		while (tab[j] != '#' && tab[j])
		{
			if ((j + 1) % 4 == 0)
			{
				s->i++;
				if (tab[j + 1] == '#')
					s->j--;
				else if (tab[j + 3] == '#')
					s->j++;
			}
		j++;
		}
		if (tab[j] == '#')
		{
			if (s->map[s->i][s->j] == '.')
				s->map[s->i][s->j] = s->c;
			if (tab[j + 1] == '#')
				s->j++;
		}
		j++;
	}
	s->nb_tetra--;
	s->c++;
	s->i = 0;
	s->j = 0;
	return (1);
}

int		find_cell_for_tetra(char *tab, t_fi *s)
{
	int j;

	j = 0;
		ft_putendl("de la merde le code du fill it!");
		printf("pos tester i:%d j:%d\n",s->i, s->j);
	while (tab[j])
	{
		//if ((j = find_hashtag_n_return_pos(tab, j, s)) >= 16)
		//	break ;
		while (tab[j] != '#' && tab[j])
		{
			if ((j + 1) % 4 == 0)
			{
				s->i++;
				if (tab[j + 1] == '#')
					s->j--;
				else if (tab[j + 3] == '#')
					s->j++;
			}
			j++;
		}
		if (j < 2 && spe_tetra(tab, j))
			return (find_cell_for_spe_tetra(s) ? 1 : 0);
		if (tab[j] == '#')
		{
			if (s->map[s->i][s->j] != '.')
				return (0);
			if (tab[j + 1] == '#')
				s->j++;
		}
		j++;
	}
	return (1);
}

int		solver(char **tab, t_fi *s)
{
	int i;
	int j;

	if (s->nb_tetra == 0)
		return (1);
	while (s->map[s->i])
	{
		while (s->map[s->i][s->j])
		{
			i = s->i;
			j = s->j;
			if (find_cell_for_tetra(tab[s->c - 'A'], s))
			{
				s->i = i;
				s->j = j;
					printf("pos trouve i:%d j:%d\n",s->i,s->j);
				fill_map_w_tetra(tab[s->c - 'A'], s);
					ft_putendl("map remplie!");
					ft_putmultistr(s->map);
				if (solver(tab, s) == 1)
					return (1);
				else
					erase_last_tetra(s);
			}
			s->i = i;
			s->j = (j + 1);
		}
		s->j = 0;
		s->i++;
	}
	return (0);
}
