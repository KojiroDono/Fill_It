/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:03:21 by auguyon           #+#    #+#             */
/*   Updated: 2018/12/10 18:29:09 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF 547

# include "Libft/libft.h"
# include<stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char		**parse_tab(char *tab, int tetrq);

#endif
