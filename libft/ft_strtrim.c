/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 07:48:45 by jhouston          #+#    #+#             */
/*   Updated: 2019/06/06 14:49:53 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int i;
	unsigned int j;
	unsigned int l;

	j = 0;
	if (s == NULL)
		return (NULL);
	while (s[j] != '\0' && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j++;
	i = ft_strlen(s);
	while (j < i && (s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t'))
		i--;
	if (j == i)
		return (ft_strnew(1));
	l = i - j;
	return (ft_strsub(s, j, l));
}
