/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:08:07 by auguyon           #+#    #+#             */
/*   Updated: 2019/01/03 13:59:26 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		print_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

void	init_struct(t_fi *s)
{
	s->map = NULL;
	size_map(s);
	s->c = 'A';
	s->i = 0;
	s->j = 0;
}

int		open_n_read(char *av, char **str)
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
	if (ft_strlen(*str) > 547)
		return (0);
	return (1);
}

int		main(int ac, char **av, char **envp)
{
	t_fi	*s;
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
	new_tab = sort_tab(str, s->nb_tetra);
	while (!solver(new_tab, s))
	{
		s->size++;
		s->i = 0;
		s->j = 0;
		alloc_map(s);
	}
	if (fillit_color_true(envp))
		print_in_color(s);
	else
		ft_putmultistr(s->map);
	return (0);
}
