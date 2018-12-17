/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:08:07 by auguyon           #+#    #+#             */
/*   Updated: 2018/12/17 20:46:41 by auguyon          ###   ########.fr       */
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
			ft_strdel((s->map) + j++);
		ft_strdel(s->map);
	}
	j = 0;
	s->map = (char**)malloc(sizeof(char*) * (s->size + 1));
	while (j < s->size)
		s->map[j++] = ft_strnew(s->size);
	s->map[s->size] = 0;
	fill_w_dot(s);
}

void 	read_in_tab(int fd, char **str)
{
	char 	buf[BUFF + 1];
	int     ret;
	
	if ((ret = read(fd, buf, BUFF)) == -1)
		return ;
	buf[ret] = '\0';
	if (!(*str = ft_strdup(buf)))
		return ;
}

int		main(int ac, char **av)
{
	t_fi	*s;
	char	**new_tab;
	char	*tab;
	int 	fd;

	s = (t_fi*)malloc(sizeof(t_fi));
	s->map = NULL;
	s->nb_tetra = 2;
	s->size = 2;
	s->c = 'A';
	s->i = 0;
	s->j = 0;
	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	read_in_tab(fd, &tab); // add function print error
	close(fd);
	if ((check_all(tab)) <= 0)
		return (print_error(-1));
	new_tab = parse_tab(tab, s->nb_tetra);
	ft_strdel(&tab);
	alloc_map(s);
//		ft_putmultistr(s->map);
	printf("test1 av solver\n");
	while (!solver(new_tab, s))
	{
			printf("realloc_map\n");
		s->size++;
		alloc_map(s);
	}
	//	ft_putmultistr(s->map);
	return (0);
}
