/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 11:08:35 by auguyon           #+#    #+#             */
/*   Updated: 2018/12/27 11:24:42 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill_w_dot(t_fi *s)
{
	int i;
	int j;

	i = 0;
	while (s->map[i] && !(j = 0))
	{
		while (j < s->size)
			s->map[i][j++] = '.';
		j = 0;
		i++;
	}
}

void	alloc_map(t_fi *s)
{
	int j;

	j = 0;
	if (s->map)
	{
		while (s->map[j])
			ft_strdel(&s->map[j++]);
		ft_strdel(s->map);
	}
	j = 0;
	if (!(s->map = (char**)malloc(sizeof(char*) * (s->size + 1))))
		return ;
	while (j <= s->size)
		s->map[j++] = ft_strnew(s->size);
	s->map[s->size] = 0;
	fill_w_dot(s);
}

int     size_map(t_fi *s)
{
    int	size;
	int nb_t;

	nb_t = s->nb_tetra;
 	nb_t *= 4;
    size = 2;
    while ((size * size) < nb_t)
        size++;
    s->size = size;
	alloc_map(s);
    return(1);
}
