/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcreturn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 14:51:35 by jhouston          #+#    #+#             */
/*   Updated: 2019/06/29 14:51:37 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcreturn(char const *s, char c, size_t x)
{
	char	*ns;
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	j = 0;
	n = 0;
	ns = ft_strnew(ft_strcnlen(s, c, x));
	if (s[i] != c)
		j++;
	while (s[i] && j <= x)
		if (s[i] == c && s[i])
		{
			while (s[i] == c && s[i])
				i++;
			if (s[i])
				j++;
		}
		else
			while (s[i] != c && s[i])
				i++;
	while (s[i] != c && s[i])
		ns[n++] = s[i++];
	return (ns);
}
