/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spe_tetra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:16:50 by auguyon           #+#    #+#             */
/*   Updated: 2018/12/20 15:23:37 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int 	spe_tetra(char *tab, int j)
{
	if (tab[j + 2] == '#' && tab[j + 3] == '#' && tab[j + 4] == '#')
		return (1);
	else if (tab[j + 1] == '#' && tab[j + 3] == '#' && tab[j + 4] == '#')
		return (1);
	else if (tab[j + 7] == '#' && tab[j + 3] == '#' && tab[j + 4] == '#')
		return (1);
	else if (tab[j + 5] == '#'  && tab[j + 3] == '#' && tab[j + 4] == '#')
		return (1);
	else if (tab[j + 8] == '#' && tab[j + 3] == '#' && tab[j + 4] == '#')
		return (1);
	else if (tab[j + 7] == '#' && tab[j + 8] == '#')
		return (1);
	return (0);
}

int		find_cell_for_spe_tetra(t_fi *s)
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
