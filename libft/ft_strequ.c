/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 13:02:19 by jhouston          #+#    #+#             */
/*   Updated: 2019/06/05 15:18:06 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(const char *ls, const char *rs)
{
	if (ls == NULL || rs == NULL)
		return (0);
	if (ft_strcmp(ls, rs) == 0)
		return (1);
	else
		return (0);
}
