/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:08:07 by auguyon           #+#    #+#             */
/*   Updated: 2018/12/28 14:59:14 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	init_struct(t_fi *s) // Initialise la struct
{
	s->map = NULL;
	size_map(s); // on trouve la taille mini de la map et on alloc pour la 1ere fois
	s->c = 'A';
	s->i = 0;
	s->j = 0;
}

int		open_n_read(char *av, char **str) // ouvre le fichier, et return si il est trop grand
{
	char	buf[BUFF + 1];
	int		ret;
	int		fd;

	fd = open(av, O_RDONLY);
	if ((ret = read(fd, buf, BUFF)) == -1)
		return (0);
	buf[ret] = '\0';
	if (!(*str = ft_strdup(buf)))
		return (0);
	close(fd);
	if (ft_strlen(str) > 547)
		return (print_error());
	return (1);
}

int		main(int ac, char **av)
{
	t_fi	*s;
	char	**new_tab;
	char	*str;

	s = (t_fi*)malloc(sizeof(t_fi)); // malloc la struct
	if (ac != 2)
		return (print_error());
	if (!open_n_read(av[1], &str))
		return (print_error());
	if ((s->nb_tetra = check_tetra_is_good(str)) <= 0) // on check si les tetra sont ok
		return (print_error());
	init_struct(s);
	new_tab = sort_tab(str, s->nb_tetra); // on range le tab dans un char** et on place toute les pieces a gauche
	while (!solver(new_tab, s)) // on resout le tetri
	{
		s->size++;
		s->i = 0;
		s->j = 0;
		alloc_map(s); // si besoin on realloc pour aggrandir la map
	}
	ft_putmultistr(s->map); // on affiche la map
	return (0);
}
