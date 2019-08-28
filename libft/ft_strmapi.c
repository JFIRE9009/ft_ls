/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 12:45:47 by jhouston          #+#    #+#             */
/*   Updated: 2019/06/06 14:50:53 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	j = ft_strlen(s);
	if (!(str = (char*)malloc(j + 1 * sizeof(char))))
		return (NULL);
	while (s != NULL && s[i] != '\0')
	{
		str[i] = s[i];
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
