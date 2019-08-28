/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 14:50:24 by jhouston          #+#    #+#             */
/*   Updated: 2019/06/29 14:50:28 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcount(char const *s, char c)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (s[i] != c && s[i])
		j++;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c && s[i])
				i++;
			if (s[i])
				j++;
		}
		else
			while (s[i] != c && s[i])
				i++;
	}
	return (j);
}
