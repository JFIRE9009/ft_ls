/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 09:31:10 by jhouston          #+#    #+#             */
/*   Updated: 2019/06/26 17:22:48 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *ls, const char *rs, size_t n)
{
	size_t i;

	if (n == 0)
		return (0);
	i = 0;
	while (ls[i] && rs[i] && ls[i] == rs[i] && i < n - 1)
		i++;
	return ((unsigned char)ls[i]) - (unsigned char)(rs[i]);
}
