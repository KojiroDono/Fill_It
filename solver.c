/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 12:17:42 by auguyon           #+#    #+#             */
/*   Updated: 2018/12/28 15:02:46 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		erase_last_tetra(t_fi *s) // on efface le tetra d'avant pour pouvoir le replacer
{
	int i;
	int j;
	int one;

	i = 0;
	one = 0;
	s->c--; // on decremente la lettre B -> A
	s->nb_tetra++; // on incremente le nb de tetra
	while (s->map[i] && !(j = 0)) // on va chercher la lettre et la remplacer par un '.'
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
		i++;
	}
	return (1);
}

int		find_hashtag_n_rpos(int j, char *tab, t_fi *s) // on cherche notre hasttag dans notre tab et on return la pos
{
	while (tab[j] != '#' && tab[j])
	{
		if ((j + 1) % 4 == 0)
		{
			s->i++;
			if (tab[j + 1] == '#' && tab[j - 1] == '#') // des conditions pour certain cas 
				s->j -= 2;
			else if (tab[j + 1] == '#' && tab[j - 2] == '#')
				s->j--;
			else if (tab[j + 2] == '#' && tab[j - 1] == '#' &&
				tab[j - 2] == '#' && tab[j - 3] == '#')
				s->j--;
		}
		j++;
	}
	return (j);
}

int		fill_map_w_tetra(char *tab, t_fi *s) // on remplie la map avec le tetra, meme fct que en dessous
{
	int j;

	j = 0;
	while (tab[j])
	{
		j = find_hashtag_n_rpos(j, tab, s);
		if (tab[j] == '#')
		{
			if (s->map[s->i][s->j] == '.')
				s->map[s->i][s->j] = s->c;
			if (tab[j + 1] == '#')
				s->j++;
		}
		j++;
	}
	s->nb_tetra--; // on decremente notre nb de tetra 
	s->c++; // on incremente notre lettre A -> B
	s->i = 0;
	s->j = 0;
	return (1);
}

int		find_cell_for_tetra(char *tab, t_fi *s) // on cherche une place pour le tetra
{
	int j;
	int i_tmp;
	int j_tmp;

	j = 0;
	i_tmp = s->i; // on garde les coodonees du debut
	j_tmp = s->j;
	while (tab[j])
	{
		j = find_hashtag_n_rpos(j, tab, s); // on cherche la pos du hashtag
		if (tab[j] == '#')
		{
			if (!s->map[s->i] || !s->map[s->i][s->j] ||
					s->map[s->i][s->j] != '.') // si la pos est libre et existe on continue
				return (0);
			if (tab[j + 1] == '#')
				s->j++;
		}
		j++;
	}
	s->i = i_tmp; // on reprend les coodonee du debut
	s->j = j_tmp;
	return (1);
}

int		solver(char **tab, t_fi *s) // la fct de backtracking
{
	int i;
	int j;

	if (s->nb_tetra == 0)
		return (1);
	while (s->map[s->i] && !(s->j = 0))
	{
		while (s->map[s->i][s->j])
		{
			i = s->i;
			j = s->j;
			if (find_cell_for_tetra(tab[s->c - 'A'], s))
			{
				fill_map_w_tetra(tab[s->c - 'A'], s);
				if (solver(tab, s) == 1)
					return (1);
				else
					erase_last_tetra(s);
			}
			s->i = i;
			s->j = (j + 1);
		}
		s->i++;
	}
	return (0);
}
