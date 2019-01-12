/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 11:08:35 by auguyon           #+#    #+#             */
/*   Updated: 2019/01/05 16:30:32 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	fill_w_dot(t_fi *s)
{
	int i;
	int j;

	i = 0;
	while (i < s->size && !(j = 0))
	{
		while (j < s->size)
			s->map[i][j++] = '.';
		i++;
	}
}

int			alloc_map(t_fi *s)
{
	s->i = 0;
	s->j = 0;
	if (s->map)
	{
		while (s->j < s->size)
			free(s->map[s->j++]);
		free(s->map);
	}
	s->j = 0;
	if (!(s->map = (char**)malloc(sizeof(char*) * (s->size + 1))))
		return (print_error(-42));
	while (s->j < s->size)
	{
		if (!(s->map[s->j] = (char*)malloc(sizeof(char*) * (s->size + 1))))
			return (print_error(-42));
		ft_bzero(s->map[s->j], s->size + 1);
		s->j++;
	}
	s->map[s->size] = 0;
	fill_w_dot(s);
	s->size++;
	s->j = 0;
	return (1);
}
