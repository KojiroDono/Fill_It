/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solverv5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 10:47:19 by auguyon           #+#    #+#             */
/*   Updated: 2018/12/20 15:21:26 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fill_map_w_tetra(char *tab, t_fi *s, int ip, int jp)
{
	int j;

	j = 0;
	while (tab[j])
	{
		while (tab[j] != '#' && tab[j])
		{
			if ((j + 1) % 4 == 0)
			{
				ip++;
				jp = 0;
				if (tab[j + 1] != '#' && (tab[j + 2] == '#' || tab[j + 3] == '#'))
					jp++;
			}
			j++;
		}
		if (tab[j] == '#')
		{
			if (s->map[ip][jp] != '.')
				return (0);
			s->map[ip][jp] = s->c;
			jp++;
			j++;
		}
	}
	s->c++;
	s->nb_tetra--;
	s->i = 0;
	s->j = 0;
		ft_putendl("map remplie !!!");
		ft_putmultistr(s->map);
	return (1);
}

int		find_cell_for_tetra(char *tab, t_fi *s)
{
	int j;

	j = 0;
	while (tab[j])
	{
		while (tab[j] != '#' && tab[j])
		{
			if ((j + 1) % 4 == 0)
			{
				s->i++; // probleme ici !
				if (tab[j + 1] != '#' && (tab[j + 2] == '#' || tab[j + 3] == '#'))
					s->j++;
			}
			j++;
		}
		if (j > 2 && spe_tetra(tab, j))
			return (check_place_spe_tetra(s) ? 1 : 0);
		if (tab[j] == '#')
		{
			if (s->map[s->i][s->j] != '.')
				return (0);
			if (tab[i + 1])
				s->j++;
			j++;
		}
	}
	return (1);
}

int		find_empty_cell(t_fi *s)
{
	while (ft_isupper(s->map[s->i][s->j]) && s->map[s->i][s->j] && s->map[s->i])
	{
		if (s->map[s->i][s->j] == '\0')
		{
			s->i++;
			s->j = 0;
		}
		s->j++;
	}
		printf("Pos map libre: i:%d j:%d\n", s->i, s->j);
		ft_putmultistr(s->map);
	if (s->map[s->i][s->j] == '.' && s->map[s->i][s->j] && s->map[s->i])
		return (1);
	return (0);
}

int		check_n_fill(char *tab, t_fi *s)
{
	int	i;
	int j;

	i = 0;
	j = 0;
		ft_putendl("Debut de check_n_fill");
	while (!find_cell_for_tetra(tab, s))
	{
		if (!find_empty_cell(s))
			return (0);
		i = s->i;
		j = s->j;
	}
		ft_putendl("Place trouvé!");
	return (fill_map_w_tetra(tab, s, i, j));

}
int		erase_last_tetra(char *tab, t_fi *s)
{
	int	i;
	int j;
	int one;

	i = 0;
	j = 0;
	one = 0;
	s->j = 0;
	s->i = 0;
	while (s->map[i])
	{
		while (s->map[i][j] && s->map[i])
		{
			if (s->map[i][j] == s->c && !one)
			{
				printf("Valeur de i:%d et j:%d \n",i, j);
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
	{
		s->c--;
		s->nb_tetra++;
	}
		printf("Erase last tetra! pos: i:%d j:%d", s->i, s->j);
		ft_putmultistr(s->map);
		ft_putendl("CONNNNNNARD!");
	return (check_n_fill(tab, s));
}

int		solver(char **tab, t_fi *s)
{
	if (s->nb_tetra == 0)
		return (1);
	while (s->map[s->i][s->j])
	{
		if (check_n_fill(tab[s->c - 'A'], s))
		{
			if (solver(tab, s) == 1)
				return (1);
			erase_last_tetra(tab[s->c - 'A'], s);
		}
	}
	return (0);
}
