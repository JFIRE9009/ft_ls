/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:14:28 by jhouston          #+#    #+#             */
/*   Updated: 2019/06/06 14:59:04 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	i = ft_strlen(s1);
	while (s2[j] != '\0')
	{
		if (n > 0)
		{
			s1[i] = s2[j];
			i++;
			j++;
			n--;
		}
		else
			break ;
	}
	s1[i] = '\0';
	return (s1);
}
