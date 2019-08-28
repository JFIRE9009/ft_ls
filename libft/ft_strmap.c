/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 09:59:02 by jhouston          #+#    #+#             */
/*   Updated: 2019/06/06 14:51:45 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	j = ft_strlen(s);
	if (!(str = (char *)malloc(j + 1 * sizeof(char))))
		return (NULL);
	while (s != NULL && s[i] != '\0')
	{
		str[i] = s[i];
		str[i] = f(s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
