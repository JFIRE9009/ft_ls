/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:50:16 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/16 15:57:17 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../lib_ls.h"

int	scan_options(int max, char **flags)
{
	int i;
	int j;
	int check;

	i = 1;
	check = 0;
	while (i < max)
	{
		j = 0;
		if (flags[i][0] == '-')
		{
			if (flags[i][j + 1] != '\0')
				while (flags[i][j])
				{
					if (flags[i][j] != '-' && flags[i][j] != 'a' && flags[i][j] != 'l' && flags[i][j] != 'r' && \
					flags[i][j] != 't' && flags[i][j] != 'R')
						unrecognized_option_error(flags[i][j]);
					SET_BIT(check, COMP(flags[i][j]));
					j++;
				}
		}
		i++;
	}
	return (check);
}
