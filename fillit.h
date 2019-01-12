/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:03:21 by auguyon           #+#    #+#             */
/*   Updated: 2019/01/11 20:14:34 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF 600

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int					g_fill_it_color;

typedef struct		s_fi
{
	char			**map;
	char			c;
	int				size;
	int				nb_tetra;
	int				i;
	int				j;
}					t_fi;

int					print_error(int error);
int					free_struct_n_str(char *str, t_fi *s);
void				free_struct(t_fi *s);

int					open_n_read(char *av, char **str);
int					parse(char *tab, t_fi *s);
int					alloc_map(t_fi *s);
char				**sort_tab(char *tab, t_fi *s);
int					solver(char **tab, t_fi *s);
int					fillit_color_true(char **envp);
void				print_in_color(t_fi *s);

#endif
