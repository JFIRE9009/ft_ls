/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:20:09 by jhouston          #+#    #+#             */
/*   Updated: 2019/06/26 17:04:24 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(src);
	j = 0;
	k = 0;
	while (dst[j] && j < dstsize)
		j++;
	while (j + k + 1 < dstsize && src[k])
	{
		dst[j + k] = src[k];
		k++;
	}
	if (j + k < dstsize)
		dst[j + k] = '\0';
	return (i + j);
}
