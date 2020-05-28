/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhouston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:49:50 by jhouston          #+#    #+#             */
/*   Updated: 2019/09/13 17:54:06 by jhouston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../lib_ls.h"

void no_file_error(char *s)
{
    ft_putstr("ft_ls: cannot access '"); 
    ft_putstr(s);
    ft_putendl("' : No such file or directory");
    exit (-1);
}

void unrecognized_option_error(char c)
{
    ft_putstr("ft_ls: unrecognized option '");
    ft_putchar(c);
    ft_putendl("' \nAvailable options: '-a' '-l' '-r' '-R' '-t'");
    exit (-1);
}

void    error_check(int max, char **flags)
{
	int i;
	int j;

	i = 1;
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
					j++;
				}
			else
				no_file_error(flags[i]);
		}
		else
			no_file_error(flags[i]);
		i++;
	}
}