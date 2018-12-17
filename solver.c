/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:08:23 by auguyon           #+#    #+#             */
/*   Updated: 2018/12/17 15:16:40 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	a_g = 2;

char	**fill_w_dot(char **map) //remplie la map de '.'
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (j <= a_g)
			map[i][j++] = '.';
		i++;
	}
	return (map);
}

void	alloc_map(t_fi s) // alloc la map a la taille de a_g
{
	int j;

	j = 0;
//	while (map[j])				// a revoir
//		ft_strclr(map[j++]);
	map = ft_memalloc(a_g + 1);
	j = 0;
	while (map[j])
		map[j++] = ft_memalloc(a_g + 1);
	fill_w_dot(map);
	return (map);
}

int		search_and_destroy(char **map, char l) // del the 2 last tetri
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == l || map[i][j] == (l - 1))
				map[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (3); // 3 for next tetra
}

int		cpy_in_map(char **map, char	**tab, int i, int ja, int ia) //remplie la map
{
	char l = 'A' + i;
	int j = 0;
	
	if (ja == 666)
		return (search_and_destroy(map, l));
	printf("Map%d :%s\n", i, map[0]);	
	printf("test\n");
	if (a_g != 3) //mauvaise condition pour la 1ere fois
	{
		while (map[ia][ja] != '.' && map[ia][ja]) //cherche lancien tetri
			ja++;
		if (map[ia][ja] == '\0')
		{
			ja = 0;
			return (cpy_in_map(map, tab, i, ja, ia++)); // change de ligne
		}
	}
	printf("Map%d :%s\n", i, map[0]);	
	printf("tab%d :%s\n", i, tab[0]);	
	while (tab[i][j])
	{
		while (tab[i][j] != '#' && tab[i][j])
		{
			j++;
			if (j % 4 == 0)
				ia++;
		}
		if (tab[i][j] == '#')
		{
			if (map[ia][ja] == '\0')
				return (-2);
			if (map[ia][ja] != '.')
				return (0);
			else
				map[ia][ja++] = l;
		}
	}
	printf("Map%d :%s\n", i, map[0]);	
	return (1);
}

char	**solver(char **map, char **tab, int tetra, int r, int i)
{
	int ia;
	int ja;

	ja = 0;
	ia = 0;
	if (r == -2 || r == -3) // -2 = realloc la map car trop petite
	{
		alloc_map(map);
		a_g++;
		r = 1;
		tetra += i;
		i = 0;
	}
	while (tetra >= 0)
	{
		if (r == 1) // 1 = last tetri good
		{
			if (!(r = cpy_in_map(map, tab, i, ja, ia)))
				return (solver(map, tab, tetra++, r, i--));
			return (solver(map, tab, tetra--, r, i++));
		}
		if (r == 0)
		{
			ja = 666;
			r = cpy_in_map(map, tab, i, ja, ia);
			return (solver(map, tab, tetra--, r, i++));
		}
		if (r == 2)
		{
			r = cpy_in_map(map, tab, i, ja, ia);
			return (solver(map, tab, tetra--, r, i + 2));
		}
		if (r == 3)
		{
			cpy_in_map(map, tab, ++i, ja, ia);
			r = 2;
			return (solver(map, tab, tetra--, r, (i--)));
		}
	}
	return (map);
}
