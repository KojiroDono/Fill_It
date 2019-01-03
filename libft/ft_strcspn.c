/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:36:59 by auguyon           #+#    #+#             */
/*   Updated: 2019/01/03 13:26:21 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *s, const char *c)
{
	size_t	i;
	size_t	j;
	size_t	b;

	i = 0;
	while (s[i] && !(j = 0))
	{
		b = i;
		while (s[b] == c[j] && s[b])
		{
			if (c[j] == '\0')
				return (i);
			b++;
			j++;
		}
		i++;
	}
	if (i)
		return (i);
	return (0);
}
