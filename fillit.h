/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:03:21 by auguyon           #+#    #+#             */
/*   Updated: 2019/01/03 13:51:04 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF 600

# include "libft/libft.h"
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
char				**sort_tab(char *tab, int tetra);
int					check_tetra_is_good(char *tab);
int					spe_tetra(char *tab, int j);
int					find_cell_for_spe_tetra(char *tab, int j, t_fi *s);
int					find_cell_for_spe_tetra2(char *tab, int j, t_fi *s);
int					size_map(t_fi *s);
void				alloc_map(t_fi *s);
int					fillit_color_true(char **envp);
void				print_in_color(t_fi *s);

#endif
