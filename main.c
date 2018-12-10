/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:08:07 by auguyon           #+#    #+#             */
/*   Updated: 2018/12/10 19:52:43 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	char	**new_tab;
	char 	*tab;
	int 	fd;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	read_in_tab(fd, &tab);
	close(fd);
//	if (!check_all(tab))
//		return (0);
	new_tab = parse_tab(tab, 9);
	ft_strclr(tab);
	return (0);
}
