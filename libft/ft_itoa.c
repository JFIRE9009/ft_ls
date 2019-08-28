/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 13:42:01 by sconstab          #+#    #+#             */
/*   Updated: 2019/06/28 14:26:29 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		j;

	j = 0;
	i = ft_intlen(n) - 1;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(s = ft_strnew(i + 1)))
		return (NULL);
	if (n < 0)
	{
		j = 1;
		n = n * -1;
		s[0] = '-';
	}
	while (i >= j)
	{
		s[i--] = (n % 10) + '0';
		n = n / 10;
	}
	return (s);
}
