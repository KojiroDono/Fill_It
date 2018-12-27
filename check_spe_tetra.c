/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spe_tetra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:16:50 by auguyon           #+#    #+#             */
/*   Updated: 2018/12/27 13:28:14 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int 	spe_tetra(char *tab, int j)
{
	if (tab[j + 1] == '#' && tab[j + 3] == '#' && tab[j + 4] == '#') //1
		return (1);
	else if (tab[j + 3] == '#' && tab[j + 4] == '#' && tab[j + 7] == '#')//2
		return (1);
	else if (tab[j + 3] == '#' && tab[j + 4] == '#' && tab[j + 8] == '#')//3
		return (1);
	else if (tab[j + 2] == '#' && tab[j + 3] == '#' && tab[j + 4] == '#')//4
		return (1);
	else if (tab[j + 2] == '#' && tab[j + 5] == '#' && tab[j + 6] == '#')//5
		return (1);
	else if (tab[j + 3] == '#'  && tab[j + 4] == '#' && tab[j + 5] == '#')//6
		return (1);	
	return (0);
}

int		find_cell_for_spe_tetra2(char *tab, int j, t_fi *s)
{
	if (tab[j + 2] == '#' && tab[j + 3] == '#' && tab[j + 4] == '#')
	{
		if (!s->map[s->i][s->j] || s->map[s->i][s->j] != '.' ||
			!s->map[s->i + 1][s->j] || s->map[s->i + 1][s->j] != '.' ||
			!s->map[s->i + 1][s->j - 1] || s->map[s->i + 1][s->j - 1] != '.' ||
			!s->map[s->i + 1][s->j - 2] || s->map[s->i + 1][s->j - 2] != '.')
			return (0);
	}
	else if (tab[j + 2] == '#' && tab[j + 5] == '#' && tab[j + 6] == '#')
	{
		if (!s->map[s->i][s->j] || s->map[s->i][s->j] != '.' ||
			!s->map[s->i + 1][s->j] || s->map[s->i + 1][s->j] != '.' ||
			!s->map[s->i + 2][s->j] || s->map[s->i + 2][s->j] != '.' ||
			!s->map[s->i + 2][s->j - 1] || s->map[s->i + 2][s->j - 1] != '.')
			return (0);
	}
	else if (tab[j + 3] == '#'  && tab[j + 4] == '#' && tab[j + 5] == '#')
	{
		if (!s->map[s->i][s->j] || s->map[s->i][s->j] != '.' ||
			!s->map[s->i + 1][s->j] || s->map[s->i + 1][s->j] != '.' ||
			!s->map[s->i + 1][s->j - 1] || s->map[s->i + 1][s->j - 1] != '.' ||
			!s->map[s->i + 1][s->j + 1] || s->map[s->i + 1][s->j + 1] != '.')
			return (0);
	}
	return (1);
}

int		find_cell_for_spe_tetra(char *tab, int j, t_fi *s)
{
	if (tab[j + 1] == '#' && tab[j + 3] == '#' && tab[j + 4] == '#')
	{
		if (!s->map[s->i][s->j] || s->map[s->i][s->j] != '.' ||
			!s->map[s->i][s->j + 1] || s->map[s->i][s->j + 1] != '.' ||
			!s->map[s->i + 1][s->j - 1] || s->map[s->i + 1][s->j - 1] != '.' ||
			!s->map[s->i + 1][s->j] || s->map[s->i + 1][s->j] != '.')
			return (0);
	}
	else if (tab[j + 3] == '#' && tab[j + 4] == '#' && tab[j + 7] == '#')
	{
		if (!s->map[s->i][s->j] || s->map[s->i][s->j] != '.' ||
			!s->map[s->i + 1][s->j] || s->map[s->i + 1][s->j] != '.' ||
			!s->map[s->i + 1][s->j - 1] || s->map[s->i + 1][s->j - 1] != '.' ||
			!s->map[s->i + 2][s->j - 1] || s->map[s->i + 2][s->j - 1] != '.')
			return (0);
	}
	else if (tab[j + 3] == '#' && tab[j + 4] == '#' && tab[j + 8] == '#')
	{
		if (!s->map[s->i][s->j] || s->map[s->i][s->j] != '.' ||
			!s->map[s->i + 1][s->j] || s->map[s->i + 1][s->j] != '.' ||
			!s->map[s->i + 1][s->j - 1] || s->map[s->i + 1][s->j - 1] != '.' ||
			!s->map[s->i + 2][s->j] || s->map[s->i + 2][s->j] != '.')
			return (0);
	}
	return(find_cell_for_spe_tetra2(tab, j, s));
}