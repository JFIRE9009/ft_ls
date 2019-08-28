/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 06:23:17 by jhouston          #+#    #+#             */
/*   Updated: 2019/06/13 08:56:14 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t i;
	size_t j;

	if (ft_strlen(n) == 0)
		return ((char *)h);
	i = 0;
	while (h[i] != '\0' && i < len)
	{
		j = 0;
		while (n[j] == h[i + j])
		{
			if ((i + j) == len)
				break ;
			if (n[j + 1] == '\0')
				return ((char *)h + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
