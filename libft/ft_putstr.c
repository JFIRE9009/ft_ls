/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 08:55:08 by jhouston          #+#    #+#             */
/*   Updated: 2019/06/24 16:08:53 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(const char *str)
{
	size_t i;

	i = 0;
	if (str == NULL)
		return ((void)NULL);
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}
