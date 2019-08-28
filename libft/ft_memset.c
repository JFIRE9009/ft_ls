/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 09:50:25 by jhouston          #+#    #+#             */
/*   Updated: 2019/07/18 09:08:00 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t count)
{
	char *str;

	if (count == 0)
		return (buf);
	str = buf;
	while (count--)
	{
		*str = ch;
		if (count)
			str++;
	}
	return (buf);
}
