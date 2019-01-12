/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:08:07 by auguyon           #+#    #+#             */
/*   Updated: 2019/01/12 17:08:49 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** For active color, "export Fill_It=True"
*/

static void	print_n_free(t_fi *s, char **new_tab)
{
	if (g_fill_it_color)
		print_in_color(s);
	else
		ft_putmultistr(s->map);
	free_struct(s);
	s->i = 0;
	while (new_tab[s->i])
		free(new_tab[s->i++]);
	free(new_tab);
}

static void	size_map(t_fi *s)
{
	int nb;

	nb = s->nb_tetra;
	nb *= 4;
	s->size = 2;
	while ((s->size * s->size) < nb)
		s->size++;
}

static void	init_struct(t_fi *s)
{
	s->map = NULL;
	size_map(s);
	if (!alloc_map(s))
		return ((void)0);
	s->c = 'A';
	s->i = 0;
	s->j = 0;
}

int			main(int ac, char **av, char **envp)
{
	char	**new_tab;
	char	*str;
	t_fi	*s;

	fillit_color_true(envp);
	if (ac == 1 || ac == 3)
		return (print_error(0));
	if (ac > 3)
		return (print_error(-1));
	if (!open_n_read(av[1], &str))
		return (0);
	if (!(s = (t_fi*)malloc(sizeof(t_fi))))
		return (print_error(-42));
	if (!parse(str, s))
		return (free_struct_n_str(str, s));
	init_struct(s);
	new_tab = sort_tab(str, s);
	while (!solver(new_tab, s))
		alloc_map(s);
	print_n_free(s, new_tab);
	return (0);
}
