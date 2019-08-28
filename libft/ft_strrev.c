/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 14:51:06 by jhouston          #+#    #+#             */
/*   Updated: 2019/07/08 13:32:11 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
/*	
	int		len;
	int		i;
	char	c;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		c = s[i];
		s[i] = s[len];
		s[len] = c;
		i++;
		len--;
	}
	return (s);
*/
	char	*str;
	int		len;
	int 	i;

	i = 0;
	ft_putnbr(len = ft_strlen(s));
	str = ft_strnew(len);
	while (s[len] != '\0')

	{
		s[i] = s[len];
		*str = s[i];
		i++;
		len--;
	}
	ft_putstr(str);
	return (str);
}

int	main(void)
{
	char *s;

	s = ft_strnew(6);
	ft_strcpy(s, "Hello");
	ft_putendl(s);
	ft_strrev(s);
	ft_putendl(s);
}
