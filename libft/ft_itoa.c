/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 20:41:56 by auguyon           #+#    #+#             */
/*   Updated: 2018/11/16 10:52:58 by auguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	unsigned int	a;
	int				b;
	int				neg;
	char			*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(b = 0) && n == 0)
		b++;
	if (!(neg = 0) && n < 0 && ++b)
		neg = 1;
	a = (neg ? -n : n);
	while (n && ++b)
		n = n / 10;
	if (!(str = (char*)malloc(sizeof(*str) * b + 1)))
		return (0);
	str[b] = '\0';
	while (b--)
	{
		str[b] = (a % 10) + '0';
		a = a / 10;
	}
	(neg ? str[0] = '-' : 1);
	return (str);
}
