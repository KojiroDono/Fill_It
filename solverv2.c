/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solverv2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 12:51:36 by auguyon           #+#    #+#             */
/*   Updated: 2018/12/15 16:25:06 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	alloc_map(t_fi lst)
{
	// alloc with t_fi.size
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

int		solver(char **tab, t_fi lst)
{
	int i = 0;
	int j = 0;
	int i_temp = 0;
	int	j_temp = 0;

	//	alloc_map(lst); // mettre ici ou en dehors de la fonction ?
	if (lst.nb_tetra == 0)
		return (1);
	if (check_map(lst))
	{
		i_temp = lst.ia;
		j_temp = lst.ja;
		while (tab[i][j])
		{
			while (tab[i][j] != '#' && tab[i][j])
			{
				if (j % 4 == 0)
				{
					lst.ia++;
					if (tab[i][j + 1] == '#')
						lst.ja = 0;
				}
				j++;
			}
			if (tab[i][j] == '#')
			{
				if (ft_isupper(map[lst.ia][lst.ja]) || map[lst.ia][lst.ja])
					return (0);
				if (tab[i][j + 1] == '#')
					lst.ja++;
			}
		}
	}
	return (0);
}
