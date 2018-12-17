/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solverv4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:17:48 by auguyon           #+#    #+#             */
/*   Updated: 2018/12/17 20:46:37 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	del_last_tetra(t_fi *s)
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
	s->nb_tetra++;
	s->c--;
	s->j++;
}

int 	check_place_tetra(char *tab, t_fi *s)
{
	int j = 0;
// probleme pour le tretro "negatif"
	while (tab[j])
	{
		while (tab[j] != '#')
		{
			if (j % 4 == 0)
			{
				s->i++;
				s->j = 0;
			}
			j++;
		}
		if (tab[j] == '#')
		{
			if (ft_isupper(s->map[s->i][s->j]) || s->map[s->i][s->j])
				return (0);
			if (tab[j + 2] == '#')
				 
			s->j++;
		}
	}
	return (1);
}

int		find_empty_cell(t_fi *s)
{
	while (ft_isupper(s->map[s->i][s->j]) && (ft_isupper(s->map[s->i + 1][s->j]) || ft_isupper(s->map[s->i][s->j + 1])))
	{
		if (s->map[s->i][s->j])
		{
			s->i++;
			s->j = 0;
		}
		s->j++;
	}
	if (!ft_isupper(s->map[s->i][s->j]) && s->map[s->i][s->j])
		return (1);
	return (0);
}

void	fill_map(char *tab, t_fi *s, int i_tmp, int j_tmp)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[j])
	{
		while (tab[j] != '#')
		{
			if (j % 4 == 0)
			{
				i_tmp++;
				if (tab[j + 1] == '#')
					j_tmp = 0;
			}
			j++;
		}
		if (tab[j] == '#')
			s->map[i_tmp][j_tmp] = s->c;
	}
	s->c++;
	s->i = 0;
	s->j = 0;
	s->nb_tetra--;
}

int		check_n_fill(char *tab, t_fi *s)
{
	int i_tmp;
	int j_tmp;

	if (!find_empty_cell(s))
		return (0);
	i_tmp = s->i;
	j_tmp = s->j;
	while (!check_place_tetra(tab, s))
	{
		if (s->i == s->size && s->j == s->size + 1)
			return (0);
		if (s->map[s->i][s->j + 1] == '\0')
		{
			s->i++;
			s->j = 0;
		}
		else
	 		s->j++;
		i_tmp = s->i;
		j_tmp = s->j;
	}
		ft_putendl("test ap check_place");
	fill_map(tab, s, i_tmp, j_tmp);
		ft_putendl("test ap fill_map");
	return (1);
}

int		solver(char **tab, t_fi *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s->nb_tetra == 0)
		return (1);
	while (s->map[s->i][s->j])
	{
		ft_putendl("test av check");
		if (check_n_fill(tab[s->c - 'A'], s))
		{
			if (solver(tab, s) == 1)
				return (1);
			if (s->c != 'A')
				del_last_tetra(s);	
		}
	}
	return (0);
}
