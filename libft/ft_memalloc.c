/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 07:10:14 by jhouston          #+#    #+#             */
/*   Updated: 2019/06/06 14:56:01 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *str;

	str = (void*)malloc(size * sizeof(size));
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
