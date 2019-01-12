/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:45:41 by auguyon           #+#    #+#             */
/*   Updated: 2019/01/05 17:32:46 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_good_pattern(char *str)
{
	int	i;
	int	dot;
	int	hashtag;

	i = -1;
	dot = 0;
	hashtag = 0;
	while (str[++i] && i < 20)
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (0);
		if (str[i] == '.')
			dot++;
		if (str[i] == '#')
			hashtag++;
	}
	if (hashtag == 4 && dot == 12)
		return (1);
	return (0);
}

static int	check_new_line(char const *str)
{
	int	i;
	int	new_line;

	i = 4;
	new_line = 0;
	while (str[i] && i < 20)
	{
		if (str[i] == '\n')
			new_line++;
		else
			return (0);
		i = i + 5;
	}
	if (str[19] == '\n' && str[20] == '\n' && str[21] == '\0')
		return (0);
	if ((new_line == 4 && str[19] == '\n' && str[20] == '\0') ||
			((new_line == 4 && str[19] == '\n' && str[20] == '\n')))
		return (1);
	return (0);
}

static int	check_link_tetra(char *str)
{
	int	i;
	int	link;

	i = -1;
	link = 0;
	while (str[++i] && i < 20)
	{
		if (str[i] == '#')
		{
			if (str[i + 1] && str[i + 1] == '#' && i < 18)
				link++;
			if (str[i + 5] && str[i + 5] == '#' && i < 14)
				link++;
			if (str[i - 1] && str[i - 1] == '#' && i > 0)
				link++;
			if (str[i - 5] && str[i - 5] == '#' && i > 4)
				link++;
		}
	}
	if (link >= 6 && link <= 8)
		return (1);
	return (0);
}

int			parse(char *tab, t_fi *s)
{
	size_t	i;
	size_t	len;
	int		tetra;

	tetra = 0;
	i = 0;
	len = ft_strlen(tab);
	while (i < len)
	{
		if (!check_good_pattern(tab + i))
			return (print_error(-4));
		if (!check_new_line(tab + i))
			return (print_error(-5));
		if (!check_link_tetra(tab + i))
			return (print_error(-6));
		tetra++;
		if (tetra >= 27)
			return (print_error(-7));
		i = i + 21;
	}
	s->nb_tetra = tetra;
	return (1);
}
