/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:16:03 by auguyon           #+#    #+#             */
/*   Updated: 2019/01/08 13:21:01 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		mod_print_error(int error)
{
	ft_putstr("\033[31;4m");
	if (error == 0)
		ft_putstr("Usage:\033[0m \033[32m ./fillit source_file\n");
	else if (error == -1)
		ft_putstr("Error:\033[0m \033[31m Too many arguments\n");
	else if (error == -2)
		ft_putstr("Error:\033[0m \033[31m Read fail\n");
	else if (error == -3)
		ft_putstr("Error:\033[0m \033[31m Wrong file\n");
	else if (error == -4)
		ft_putstr("Error:\033[0m \033[31m Not valid tetriminos\n");
	else if (error == -5)
		ft_putstr("Error:\033[0m \033[31m Too many new line\n");
	else if (error == -6)
		ft_putstr("Error:\033[0m \033[31m Bad links between tetriminos\n");
	else if (error == -7)
		ft_putstr("Error:\033[0m \033[31m Too many tetriminos\n");
	else if (error == -42)
		ft_putstr("Error:\033[0m \033[31m Allocation fail\n");
	ft_putstr("\033[0m");
	return (0);
}

int		print_error(int error)
{
	if (g_fill_it_color)
		mod_print_error(error);
	else
	{
		if (error == 0)
			ft_putendl("usage: ./fillit source_file");
		else
			ft_putendl("error");
	}
	return (0);
}

void	free_struct(t_fi *s)
{
	s->i = 0;
	if (s->map)
	{
		while (s->map[s->i])
			free(s->map[s->i++]);
		free(s->map);
	}
	free(s);
}

int		free_struct_n_str(char *str, t_fi *s)
{
	free(str);
	free(s);
	return (0);
}
