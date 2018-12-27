/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:08:07 by auguyon           #+#    #+#             */
/*   Updated: 2018/12/27 13:40:10 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	init_struct(t_fi *s)
{
	s->map = NULL;
	size_map(s);
	s->c = 'A';
	s->i = 0;
	s->j = 0;
}

int 	open_n_read(char *av, char **str)
{
	char 	buf[BUFF + 1];
	int     ret;
	int		fd;
	
	fd = open(av, O_RDONLY);
	if ((ret = read(fd, buf, BUFF)) == -1)
		return (0);
	buf[ret] = '\0';
	if (!(*str = ft_strdup(buf)))
		return (0);
	close(fd);
	return (1);
}

int		main(int ac, char **av)
{
	t_fi	*s = NULL;
	char	**new_tab;
	char	*str;

	s = (t_fi*)malloc(sizeof(t_fi));
	if (ac != 2)
		return (print_error());
	if (!open_n_read(av[1], &str))
		return (print_error());
	if ((s->nb_tetra = check_tetra_is_good(str)) <= 0)
		return (print_error());
	init_struct(s);
	new_tab = parse_tab(str, s->nb_tetra);
	while (!solver(new_tab, s))
	{
		s->size++;
		s->i = 0;
		s->j = 0;
		alloc_map(s);
	}
	// cree une fct qui affiche le resultat, avec les couleurs ?
	ft_putendl("MAP FINAL");
	ft_putendl("--------");
	ft_putmultistr(s->map);
	ft_putendl("--------");
	return (0);
}
