/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 08:19:45 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/05 11:17:53 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *ls, const char *rs)
{
	size_t i;

	if (!ls || !rs)
		return (-1);
	i = 0;
	while (ls[i] == rs[i] && ls[i] != '\0')
		i++;
	return ((unsigned char)ls[i] - (unsigned char)rs[i]);
}
