/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solverv4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:17:48 by auguyon           #+#    #+#             */
/*   Updated: 2018/12/19 13:33:54 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	del_last_tetra(t_fi *s) // on delete le dernier tetra placer pour le replacer a +1
{
	int i;
	int j;
	int one;

	one = 0;
	i = 0;
	j = 0;
	while (s->map[i])
	{
		while (s->map[i][j] != s->c && s->map[i][j])
		{
			if (s->map[i][j] == s->c && !one)
			{
				s->i = i;
				s->j = j;
				one++;
			}
			if (s->map[i][j] == s->c)
				s->map[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	s->j++;
	if (s->c != 'A')
		s->c--;
}

void	fill_map(char *tab, t_fi *s, int i_tmp, int j_tmp) // apres avoir trouver une emplacement on le remplie
{
	int j;
	int compt;

	j = 0;
	compt = 0;
	ft_putmultistr(s->map);
	ft_putendl("entree de fill_map");
	while (tab[j])
	{
		while (tab[j] != '#' && tab[j])
		{
			if ((j + 1) % 4 == 0)
			{
				i_tmp++;
				if (tab[j + 1] == '#')
					j_tmp = 0;
			}
			j++;
		}
		if (tab[j] == '#' && compt != 4)
		{
			compt++;
			s->map[i_tmp][j_tmp++] = s->c;
		}
		j++;
	}
	ft_putendl("piece rempli:");
	ft_putmultistr(s->map);
	ft_putchar('\n');
	s->c++;
	s->i = 0;
	s->j = 0;
	s->nb_tetra--;
}

int		check_place_spe_tetra(t_fi *s) // le code degeulasse
{
	if (!s->map[s->i + 1][s->j - 2] || !s->map[s->i + 1][s->j - 2] || ft_isupper(s->map[s->i + 1][s->j - 2]) || ft_isupper(s->map[s->i + 1][s->j - 1]) || ft_isupper(s->map[s->i + 1][s->j]))
		return (0);
	else if (!s->map[s->i + 1][s->j - 1] || ft_isupper(s->map[s->i + 1][s->j - 1]) || ft_isupper(s->map[s->i + 1][s->j]) || ft_isupper(s->map[s->i][s->j + 1]))
		return (0);
	else if (!s->map[s->i + 1][s->j - 1] || ft_isupper(s->map[s->i + 1][s->j - 1]) || ft_isupper(s->map[s->i + 1][s->j]) || ft_isupper(s->map[s->i + 2][s->j]))
		return (0);
	else if (!s->map[s->i + 2][s->j - 1] || ft_isupper(s->map[s->i + 2][s->j - 1]) || ft_isupper(s->map[s->i + 2][s->j]) || ft_isupper(s->map[s->i + 1][s->j]))
		return (0);
	else if (!s->map[s->i + 1][s->j - 1] || ft_isupper(s->map[s->i + 1][s->j - 1]) || ft_isupper(s->map[s->i + 1][s->j]) || ft_isupper(s->map[s->i + 1][s->j + 1]))
		return (0);
	else if (!s->map[s->i + 1][s->j - 1] || !s->map[s->i + 2][s->j - 1] || ft_isupper(s->map[s->i + 1][s->j - 1]) || ft_isupper(s->map[s->i + 1][s->j]) || ft_isupper(s->map[s->i + 2][s->j - 1]))
		return (0);
	return (1);
}

int 	check_place_tetra(char *tab, t_fi *s) // on regarde si il y a de place pour notre tetra
{
	int j = 0;

	ft_putendl("entree de check");
	printf("pos map : i:%d j:%d\n", s->i, s->j);
//	printf("tab:%s map:%s\n", tab, s->map[0]);
	while (tab[j])
	{
		while (tab[j] != '#' && tab[j])
		{
			if ((j + 1) % 4 == 0)
			{
				s->i++;
				s->j = 0;
			}
			j++;
		}
		if ((tab[j + 2] == '#' && tab[j + 3] == '#' && tab[j + 4] == '#') || ((tab[j + 1] == '#' || tab[j + 8] == '#' || tab[j + 5] == '#' || tab[j + 7] == '#') && (tab[j + 3] == '#' && tab[j + 4] == '#')) || ((tab[j + 7] == '#') && (tab[j + 8] == '#')))
		{
			ft_putendl("if du tetra SPECIAL");
			return (check_place_spe_tetra(s) ? 1 : 0);
		}
		if (tab[j] == '#')
		{
			if (!s->map[s->i][s->j] || !s->map[s->i])
				return (0);
			if (ft_isupper(!s->map[s->i][s->j]))
				return (0);
			// condition d'arret si la pos est mauvaise
			s->j++;
			j++;
		}
	}
	ft_putendl("place trouve !");
	return (1);
}

int		find_empty_cell(t_fi *s)   // on cherche une place vide +1 a droite || +1 en bas
{
	while (s->map[s->i][s->j] && s->map[s->i] && (ft_isupper(s->map[s->i][s->j]) && (ft_isupper(s->map[s->i + 1][s->j]) || ft_isupper(s->map[s->i][s->j + 1]))))
	{
		if (s->map[s->i][s->j] == '\0')
		{
			s->i++;
			s->j = 0;
		}
		s->j++;
	}
	printf("find emptyyy pos map : i:%d j:%d\n", s->i, s->j);
	if (!ft_isupper(s->map[s->i][s->j]) && s->map[s->i][s->j] && s->map[s->i])
		return (1);
	return (0);
}

int		check_n_fill(char *tab, t_fi *s) // fct mere 
{
	int i_tmp;
	int j_tmp;

	ft_putendl("Debut de check_n_fill");
	s->i = 0;
	s->j = 0;
	if (!find_empty_cell(s)) // on trouve la 1ere case vide
			return (0);
	i_tmp = s->i;
	j_tmp = s->j;
	while (!check_place_tetra(tab, s)) // on cherche lendroit ou on peut placer le tetra, si on trouve pas on retourne 0
	{
		if (!find_empty_cell(s))
			return (0);
		i_tmp = s->i;
		j_tmp = s->j;
	}
	fill_map(tab, s, i_tmp, j_tmp); // si on as trouver un emplacement , on le place et on passe au tetra suivant
	return (1);
}

int		solver(char **tab, t_fi *s)
{
	if (s->nb_tetra == 0)
		return (1);
			ft_putendl("test av check");
			ft_putmultistr(s->map);
		if (check_n_fill(tab[(s->c - 'A')], s))
		{
			if (solver(tab, s) == 1)
				return (1);
			del_last_tetra(s);
		}
	return (0);
}
