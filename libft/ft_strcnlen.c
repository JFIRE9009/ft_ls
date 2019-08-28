/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcnlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 14:52:20 by jhouston          #+#    #+#             */
/*   Updated: 2019/06/29 14:52:22 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcnlen(char const *s, char c, size_t x)
{
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	j = 0;
	n = 0;
	if (s[i] != c)
		j++;
	while (s[i] && j <= x)
	{
		if (s[i] == c)
		{
			while (s[i] == c && s[i])
				i++;
			j++;
		}
		else
			while (s[i] != c && s[i])
				i++;
	}
	while (s[i++] != c && s[i])
		n++;
	return (n);
}
