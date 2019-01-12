/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_in_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 12:39:35 by auguyon           #+#    #+#             */
/*   Updated: 2019/01/04 17:37:44 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			fillit_color_true(char **envp)
{
	int i;

	i = 0;
	while (envp[i])
	{
		if (ft_strcmp(envp[i], "Fill_It=True") == 0)
		{
			g_fill_it_color = 1;
			return (1);
		}
		i++;
	}
	g_fill_it_color = 0;
	return (0);
}

static int	what_color(t_fi *s, int i, int j)
{
	int color;

	color = 31;
	if ((s->map[i][j] - 'A') >= 24)
		color = 31 + ((s->map[i][j] - 'A') - 24);
	else if ((s->map[i][j] - 'A') >= 18)
		color = 41 + ((s->map[i][j] - 'A') - 18);
	else if ((s->map[i][j] - 'A') >= 12)
		color = 31 + ((s->map[i][j] - 'A') - 12);
	else if ((s->map[i][j] - 'A') >= 6)
		color = 41 + ((s->map[i][j] - 'A') - 6);
	else if ((s->map[i][j] - 'A') < 6)
		color = 31 + (s->map[i][j] - 'A');
	return (color);
}

static void	print_code_color(t_fi *s, int i, int j)
{
	int color;

	ft_putstr("\033[");
	color = what_color(s, i, j);
	ft_putnbr(color);
	if (s->map[i][j] >= 'G' && s->map[i][j] <= 'L')
		ft_putstr(";30");
	else if (s->map[i][j] >= 'M' && s->map[i][j] <= 'R')
		ft_putstr(";1");
	else if (s->map[i][j] >= 'S' && s->map[i][j] <= 'X')
		ft_putstr(";30;1");
	else if (s->map[i][j] >= 'Y' && s->map[i][j] <= 'Z')
		ft_putstr(";0;7");
	ft_putchar('m');
	ft_putchar(s->map[i][j]);
	ft_putstr("\033[0m");
}

void		print_in_color(t_fi *s)
{
	s->i = 0;
	while (s->map[s->i] && !(s->j = 0))
	{
		while (s->map[s->i][s->j])
		{
			if (ft_isupper(s->map[s->i][s->j]))
				print_code_color(s, s->i, s->j);
			else
				ft_putchar(s->map[s->i][s->j]);
			s->j++;
		}
		ft_putchar('\n');
		s->i++;
	}
}
