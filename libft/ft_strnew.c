/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 11:20:15 by jhouston          #+#    #+#             */
/*   Updated: 2019/06/06 14:49:19 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	void *str;

	str = (void*)malloc(size + 1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}
