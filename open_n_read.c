/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_n_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 17:30:02 by auguyon           #+#    #+#             */
/*   Updated: 2019/01/05 17:31:54 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	wrong_file(char *str)
{
	int	i;

	i = 0;
	while (str[i] && i < 20)
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int			open_n_read(char *av, char **str)
{
	char	buf[BUFF + 1];
	int		ret;
	int		fd;

	fd = open(av, O_RDONLY);
	if ((ret = read(fd, buf, BUFF)) == -1)
		return (print_error(-2));
	buf[ret] = '\0';
	if (ft_strlen(buf) == 0)
		return (print_error(-3));
	if (!(*str = ft_strdup(buf)))
		return (print_error(-42));
	close(fd);
	if (!wrong_file(*str))
	{
		ft_strdel(str);
		return (print_error(-3));
	}
	return (1);
}
