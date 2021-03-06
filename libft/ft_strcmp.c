/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:08:35 by auguyon           #+#    #+#             */
/*   Updated: 2018/11/15 14:18:38 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	while ((*s1 == *s2) && *s1)
		s1++ && s2++;
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
