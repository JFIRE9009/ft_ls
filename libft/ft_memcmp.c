/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 08:17:51 by jhouston          #+#    #+#             */
/*   Updated: 2019/06/19 15:05:41 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ls, const void *rs, size_t n)
{
	const unsigned char	*left;
	const unsigned char	*right;
	size_t				i;

	i = 0;
	left = (const unsigned char *)ls;
	right = (const unsigned char *)rs;
	if (n == 0)
		return (0);
	while (n--)
	{
		if (left[i] != right[i])
			return (left[i] - right[i]);
		i++;
	}
	return (0);
}
