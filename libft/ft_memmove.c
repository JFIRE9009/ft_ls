/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 10:31:11 by jhouston          #+#    #+#             */
/*   Updated: 2019/06/08 15:23:25 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	i = len;
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (dest > src)
	{
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	else
		dest = ft_memcpy(dest, src, len);
	return (dest);
}
