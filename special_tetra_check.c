/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_tetra_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 14:41:39 by auguyon           #+#    #+#             */
/*   Updated: 2018/12/28 15:05:52 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		spe_tetra(char *tab, int j)
{
	if (tab[j + 1] == '#' && tab[j + 3] == '#' && tab[j + 4] == '#')
		return (1);
	else if (tab[j + 3] == '#' && tab[j + 4] == '#' && tab[j + 7] == '#')
		return (1);
	else if (tab[j + 3] == '#' && tab[j + 4] == '#' && tab[j + 8] == '#')
		return (1);
	else if (tab[j + 2] == '#' && tab[j + 3] == '#' && tab[j + 4] == '#')
		return (1);
	else if (tab[j + 2] == '#' && tab[j + 5] == '#' && tab[j + 6] == '#')
		return (1);
	else if (tab[j + 3] == '#' && tab[j + 4] == '#' && tab[j + 5] == '#')
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
	else if (tab[j + 3] == '#' && tab[j + 4] == '#' && tab[j + 5] == '#')
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
	return (find_cell_for_spe_tetra2(tab, j, s));
}
