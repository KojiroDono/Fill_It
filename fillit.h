/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:03:21 by auguyon           #+#    #+#             */
/*   Updated: 2018/12/17 20:46:43 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF 547

# include<stdio.h>
# include "Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_fi
{
	char			**map;
	char			c;
	int				size;
	int				nb_tetra;
	int				i;
	int				j;
}					t_fi;

int					solver(char **tab, t_fi *s);
char				**parse_tab(char *tab, int tetra);
int					check_all(char *str);
int					print_error(int i);

#endif
