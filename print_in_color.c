/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_in_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 12:39:35 by auguyon           #+#    #+#             */
/*   Updated: 2019/01/03 13:54:21 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fillit_color_true(char **envp)
{
	int i;

	i = 0;
	while (envp[i])
	{
		if (ft_strcmp(envp[i], "Fill_It=True") == 0)
			return (1);
		i++;
	}
	return (0);
}

int		what_color(t_fi *s, int i, int j)
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

void	print_code_color(t_fi *s, int i, int j)
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

void	print_in_color(t_fi *s)
{
	int	i;
	int	j;

	i = 0;
	while (s->map[i] && !(j = 0))
	{
		while (s->map[i][j])
		{
			if (ft_isupper(s->map[i][j]))
				print_code_color(s, i, j);
			else
				ft_putchar(s->map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
